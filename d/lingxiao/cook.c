// Room: /d/lingxiao/cook.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","厨房");
	set("long",@LONG
这里是凌霄城的厨房。一阵饭菜的香味充盈其间。一个凌霄弟子满
头大汗，正在做饭。他做饭方法倒也特别，人绑在一根倒吊的绳子上，
用一个奇大的铲子来搅动一口极大的锅。听说是白自在去少林寺考察回
来后，要求每一个轮值做饭的弟子都要这样干，利于练功云云……你可
以用(serve)，来获得饭菜。
LONG);
	set("exits",([
		"west" : __DIR__"zoulang2",
	]));
	set("objects",([
		__DIR__"npc/dizi" : 1,
	]));
	set("ricewater", 5);
	set("no_fight","1");
	set("coor/x", -30980);
	set("coor/y", -8870);
	set("coor/z", 140);
	setup();
}
int valid_leave(object me, string dir)
{
	if ( present("soup", me) || present("rice", me))
	return notify_fail("凌霄弟子看了你一眼，吃饭家伙你要拿到哪去？\n");
	return ::valid_leave(me, dir);
}
void init()
{
	add_action("do_serve","serve");
}
int do_serve()
{
	object me = this_player();
	object food;
	object water;

	if (me->query("family/family_name") != "凌霄城")
		return notify_fail("凌霄弟子道：你又不是凌霄城的，走开。\n");
	if(present("rice",this_player()) ) 
		return notify_fail("凌霄弟子道：吃完了再拿，别浪费食物。\n");
	if(present("rice",this_object()) ) 
		return notify_fail("凌霄弟子道：吃完了再拿，别浪费食物。\n");
	if (query("ricewater")>0)
	{
		message_vision("凌霄弟子笑道:你慢用。\n",me);
		food=new(__DIR__"obj/rice");
		water=new(__DIR__"obj/soup");
		food->move(me);
		water->move(me);
		add("ricewater",-1);
	}
	else 
		message_vision("弟子对$N歉声道: 嗨，吃的喝的都没了。\n",me);
	return 1; 
}

