// Room: /heizhao/houxiang.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "后厢");
	set("long", @LONG
这里是桃源寺的厨房，一个老和尚正在灶边忙来忙去，看来他
就是这里的大师傅了。如果你的肚子饿了，就赶快要 (serve)些吃
的吧。
LONG );
	set("no_clean_up", 0);
	set("no_fight", 1);
	set("objects", ([
		__DIR__"npc/laoheshang" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"chanyuan",
	]));
	set("ricewater", 5);
	set("coor/x", -5020);
	set("coor/y", -1190);
	set("coor/z", 50);
	setup();
}

void init()
{
        add_action("do_serve","serve");
}

int do_serve()
{
	object food, water, me = this_player(), ob = this_object();

	if (me->query("family/family_name") != "大理段家")
return notify_fail("老和尚道：阿弥陀佛，你非本派弟子，不能拿取食物。\n");
	if(present("mifang", me) || present("qingtang", me)) 
return notify_fail("老和尚道：阿弥陀佛，吃完了再拿，别浪费食物。\n");
	if(present("mifang", ob) || present("qingtang", ob)) 
return notify_fail("老和尚道：吃完了再拿，别浪费食物。\n");
	if (query("ricewater")>0)
	{
		message_vision("老和尚连声答应，给$N一碗清汤和一碗米饭。\n",me);
		food=new(__DIR__"obj/mifang");
		water=new(__DIR__"obj/qingtang");
		food->move(me);
		water->move(me);
		add("ricewater",-1);
	}
	else 
		message_vision("老和尚对$N歉声道: 嗨，吃的喝的都没了。\n",me);
	return 1; 
}
int valid_leave(object me,string dir)
{
        if(dir=="south" && (present("mifang", me) || present("qingtang", me))) 
             return notify_fail("老和尚说道：吃了就别带走。\n");
        return ::valid_leave(me,dir);
}