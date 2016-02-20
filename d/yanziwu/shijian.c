//ROOM: /d/yanziwu/shijian.c

inherit ROOM;

string look_muzhuang();
void back(object me);
void init();
int do_jump();
void reset();

void create()
{
	set("short", "试剑台");
	set("long",@LONG
玉石栏杆围成的一座石台，慕容世家的弟子经常在此切磋武技，台
角放着刀枪剑戟等十八般兵器。栏杆外水面上东一簇，西一簇的立着一
些木桩(muzhuang)。
LONG );
	set("outdoors", "yanziwu");
	set("exits", ([
		"south"  : __DIR__"changlang",
	]));
	set("item_desc",([
		"muzhuang" : ( :look_muzhuang:),
	]));
	set("no_clean_up", 0);
	set("coor/x", 840);
	set("coor/y", -1510);
	set("coor/z", 10);
	setup();
}

string look_muzhuang()
{
return  "你定睛看来，看似平淡无奇的一簇木桩，却内涵八卦五行之变。\n"
	"再多看一会儿，你觉得头晕目眩起来。原来这是慕容世家子弟用\n"
	"来练习轻功的地方，你是不是要跳上去(jump)一试身手呢。\n";
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump ()
{
	object room;
	object me = this_player () ;

	if( !(room = find_object(__DIR__"muzhuang")) )
		room = load_object(__DIR__"muzhuang");
	if( room = find_object(__DIR__"muzhuang") )
	if((int)room->query_temp("mu_trigger")==1 )
	{
		message_vision("$N一个纵身飞向木桩，身形甚是潇洒...猛然$N又飞了回来，真怪。", me) ;
		me -> move( __DIR__"muzhuang");
		me -> move( __DIR__"shijian");
		tell_object(me,"原来是你突然发现有个人影在木桩上晃动，急中生智，空中\n硬生生一个回身，飞了回来。");
		return 1 ;
	}
	room->set_temp("mu_trigger", 1);
	message_vision("$N一跃身飞上木桩，真是帅呆酷毙了。\n", me );
	me->move(room) ;
	tell_object(me,"\n你一踏上木桩，豪气勃发，脚下倒踩七星步，口中长啸作龙吟:\n“沧海笑，滔滔两岸潮...”\n"  ) ;
	call_out("back", 6 , me );
	room->delete_temp("mu_trigger");
	return 1 ;
}

void back( object me )
{
	int c_exp,c_skill;
	me->move(__DIR__"shijian");
	message_vision("$N一式飞身飞上台来，把周围的人都吓了一跳。\n",me);
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("dodge",1);
	me->add("qi",-10);
	me->add("eff_qi",-2);
	if (((c_skill*c_skill*c_skill/10)< c_exp) && (c_skill<101))
	{
		me->improve_skill("dodge", 2*(int)me->query_skill("dodge", 1));
		tell_object(me,"你的基本轻功进步了!\n");
	}
}

void reset()
{
	object room;

	::reset();
	if( room = find_object(__DIR__"muzhuang") ) room->delete("mu_trigger");
} 
