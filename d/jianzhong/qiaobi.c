#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","峭壁");
	set("long",@LONG
这个峭壁有如一座极大的屏风，冲天而起，峭壁中央离
地约二十余丈处，生着一块三四丈见方的大石，便似一个平
台，石上隐隐刻得有字。极目望去，是「剑冢」二字。峭壁
上每隔数尺就生着一丛青苔，不知道如何形成的。
LONG
	);
	set("exits",([
		"west":__DIR__"donghou1",
		"south":__DIR__"donghou1",
		"east":__DIR__"donghou1",
	]));
	set("outdoors", "jianzhong");
	set("coor/x", -401);
	set("coor/y", -421);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_climb","climb");
	add_action("do_wa","wa");
	add_action("do_wa","挖");
	add_action("do_wa","dig");
}

int do_climb(string arg)
{
	object me=this_player();
	if((arg=="青苔")||(arg=="qingtai")) return notify_fail("青苔这么滑，如何能爬？\n");
	if((arg!="峭壁")&&(arg!="bi")&&(arg!="qiaobi")) return notify_fail("你要爬什么？\n");
	if(!this_object()->query("dig_qingtai") || (this_object()->query("dig_qingtai")==0))
		return notify_fail("峭壁上长满青苔，不先挖去，如何能爬？\n");
	message_vision("$N顺着挖出的二十来个小坑，尝试着向峭壁上爬去。\n",me);
	me->start_busy(1);
	call_out("check_trigger",1,me);
	return 1;
}
void check_trigger(object me)
{
	object room;
       if( !(room = find_object(__DIR__"qiaobi1")) )	
		room = load_object(__DIR__"qiaobi1");
	if( room = find_object(__DIR__"qiaobi1") ) 
	{
		if(room->query("climb_trigger")==0)
		{
			message_vision("$N在峭壁上越爬越高……\n",me);
			room->set("climb_trigger",1);
			me->move(room);
			call_out("check_dodge",0,me,room);
		}	else	write("峭壁上有人正在攀登。\n");
	
	}
}
void check_dodge(object me,object room)
{
	if(((int)me->query("combat_exp")<50000)||(me->query_dex()<30))
	{
		message_vision(HIR"一阵大风吹来，$N没有抓牢，一下子从峭壁上摔了下来……\n"NOR,me);
		me->move(__DIR__"qiaobi");
		room->set("climb_trigger",0);
		message("vision",me->query("name")+"突然从峭壁上摔了下来。\n",environment(me),me);
		if( (int)me->query_skill("dodge",1) > 50 )
			me->unconcious();
		else 
		{
			me->set_temp("last_damage_from", "从悬崖摔下来");
			me->die();
		}
	} else
	if(((int)me->query("combat_exp")<100000)||(me->query_dex()<32))
	{
		message_vision(HIY"一阵大风吹来，$N只觉得自己头昏眼花，摇摇欲坠，只好原路爬回。\n"NOR,me);
		me->move(__DIR__"qiaobi");
		room->set("climb_trigger",0);
		message("vision",me->query("name")+"垂头丧气从峭壁上爬了下来。\n",environment(me),me);
		me->receive_damage("qi",80);
		me->receive_damage("jing",50);
	} else 
	{
		message_vision(HIC"一阵大风吹来，把$N的衣角吹得「咧咧」直响，可$N在峭壁上纹丝不动。\n"NOR,me);
		me->start_busy(1);
		call_out("climb_finish",1,me,room);
	}
}
void climb_finish(object me,object room)
{
	message_vision("$N稍吸了口气，又继续向上爬，一边爬一边挖去上面小坑中的青苔。\n",me);
	me->move(__DIR__"jianzhong");
	room->set("climb_trigger",0);
	message("vision","你终于爬上了峭壁上的「剑冢」。\n",me);
	message("vision",me->query("name")+"从峭壁下爬了上来。\n",environment(me),me);
}
int do_wa(string arg)
{
	if((arg!="qingtai")&&(arg!="青苔"))
		return notify_fail("你要挖什么？\n");
	if(this_object()->query("dig_qingtai")>0)
		return notify_fail("有人已经挖过了。\n");
	message("vison","你把峭壁上较低的青苔都用手挖去了。\n",this_player());
	message("vison",this_player()->query("name")+"把峭壁上较低的青苔都用手挖去了。\n",environment(this_player()),this_player());
	this_object()->set("dig_qingtai",1);
	return 1;
}