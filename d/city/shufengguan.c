// Room: /city/shufengguan.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;
int pushing();
int halt_pushing();
void create()
{
	set("short", "疏峰馆");
	set("long", @LONG
屋内陈列千姿百态的玲珑怪石，与馆外怪石遥相呼应。目力所及，
到处皆石，而又各不相同。于此处凭栏，可览可眺，可歌可啸。全园景
物，全在指顾间。在那明月当空之际，大有“天下三分明月色，二分无
奈在扬州”之感，因而此馆又名“二分明月楼”。
LONG );
	set("exits", ([
		"east"	: __DIR__"hushishanzi",
	]));
	set("objects", ([
		__DIR__"obj/qishayan": random(2),
	]));
	set("coor/x", -11);
	set("coor/y", -47);
	set("coor/z", 0);
	set("no_quest",1);
	setup();
}

void init()
{
	add_action( "push_stone", "push" );
}

int push_stone(string arg) 
{
	object me = this_player();
	object room;
	object parter;
	string target, dir;

	if ( !arg ) return 0;
	if ( me->is_busy() ) return 0;
	
	if ( arg == "stone" || arg == "shitou" || arg == "shi tou" )
	{
		if ( query_temp( "pushed" ) )
		{
			message_vision( "$N用力将情人石推开，一对“情人”渐渐分开，回复原位，一切回复原状。。\n", me );
			delete_temp( "pushed" );
			delete( "exits/down" );
			if ( room = find_object( __DIR__"dixiashi" ) )
				room->delete( "exits/up" );
			return 1;
		}
	}

	write ( arg );
	if ( sscanf( arg, "%s %s", target, dir ) != 2 ) return 0;
	if ( target != "stone" && target != "shitou" && target != "shi tou" )
	return notify_fail( "你要推什么？\n" );
	if ( dir != "east" && dir != "west" )
	return notify_fail( "你想把情人石往那边推？\n" );
	if ( parter = (object)query_temp( "push_" + dir ) )
	return notify_fail( parter->name() + "已经在把情人石往这边推了。\n" );
	if ( me->query_str() <= 30 )
	return notify_fail( "你试着推了情人石，但是发现推不动。\n" );
	if ( query_temp( "pushed" ) )
	return notify_fail( "情人石已经被推得合在一起了。\n" );
	if ( !query_temp( "push_" + dir ) )
	set_temp( "push_" + dir, me );
	me->set_temp("direction", dir );
	me->set_temp( "push_marks", 71 );
	message_vision( "$N发力把情人石的一块往对面推去。\n", me );
	me->start_busy( (:pushing:), (:halt_pushing:) );
	return 1;
}

int pushing()
{
	object ob, me;
	string c_dir, dir;
	int marks, force;

	me = this_player();
	dir = me->query_temp( "direction" );
	marks = me->query_temp( "push_marks" );
	force = me->query( "force_factor" );
	
	if ( dir == "west" )
	{ 
		dir = "east";
		c_dir = "西边";
	}
	else
	{
		dir = "west";
		c_dir = "东边";
	}
	if ( marks > 70 )
	{
		me->add_temp( "push_marks", -10 );
		me->add( "force", force );
		return 1;
	}
	force *= -1;
	me->add( "force", force );
	if ( me->query( "force" ) < 0 )
	{
		write( "你正用力推动情人石，突然感到体内真气枯竭。\n" );
		me->unconcious();
		if ( !query_temp( "push_" + dir ) )
			message_vision( "情人石渐渐又退回原位。\n", me );
		remove_call_out( "del_temp" );
		call_out( "del_temp", 1 );
		me->delete_temp( "push_marks" );
		return 0;
	}
	if ( !query_temp( "push_" + dir ) )
	{
		if ( marks > 10 )
		{
			me->add_temp( "push_marks", -10 );
			if ( random(5) > 2 )
				message_vision( "$N用力推动情人石，情人石发出“喀喀”的声音，逐渐向另一个靠去。\n", me );
			return 1;
		}
		else
		{
			if ( !query_temp( "pushed" ) ) 
			{
				write("你推了好久情人石，却无法将其合在一切。");
				message_vision("$N停止推动情人石，情人石渐渐又退回原位。\n", me );
			
			}
			remove_call_out( "del_temp" );
			call_out( "del_temp", 1 );
			me->delete_temp( "push_marks" );
			return 0;
		}
	}
	else
	{
		ob = query_temp( "push_" + dir );
		if ( dir = "east" )
		{
			message_vision( "$N和$n"
			"各自发力推动情人石的一块，情人石发出“喀喀”的声音，渐渐\n" + "的相互接近，一对“情人”终于拥在一起！！\n", me, ob );
			message_vision( "情人石缓缓的开始转动，向一旁移去，在屋内的地上现出一个大洞。\n", me);
			set( "exits/down" , __DIR__"dixiashi" );
			ob->set_temp( "push_marks", 1 );
		}
		remove_call_out( "del_temp" );
		call_out( "del_temp", 2 );
		me->delete_temp( "push_marks" );
		set_temp( "pushed", 1 );
		return 0;
	}
	return 0;	
}

int halt_pushing()
{
	object me = this_player();

	remove_call_out( "del_temp" );
	call_out( "del_temp", 1 );
	me->delete_temp( "direction" );
	me->delete_temp( "push_marks" );
	message_vision( "$N停止推动情人石，情人石渐渐又退回原位。\n", me );
	return 1;
}

void del_temp()
{
	object me = this_player();
	delete_temp( "push_east" );
	delete_temp( "push_west" );
	if ( me->query_temp( "direction") )
		me->delete_temp( "direction" );
}
 