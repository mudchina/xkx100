// Room: /d/baituo/shulin1.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void init();
int cut(string);

void create()
{
	set("short","树林");
	set("long", @LONG
这里是一片茂密的树林(wood)。常有樵夫来此劳作，砍了柴薪下山
货卖。树林里的小路旁边立着一张木牌(pai)。
LONG);
	set("exits",([
		"east" : __DIR__"shulin",
		"southwest" : __DIR__"caomeidi",
	]));
	set("outdoors", "baituo");
	set_temp("times" , 5);
	set("no_clean_up", 0);
	set("item_desc", ([
		"pai" : "保护树林  适量砍伐\n",
		"wood" :"一片可砍伐的树林。\n",
	]) );
	set("coor/x", -50040);
	set("coor/y", 20020);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_cut","cut");
}

int do_cut(string arg)
{
	object me=this_player();
	object ob;
	if (!arg||arg!="wood") return notify_fail("你要砍什么？\n");
	if (present("chai dao",me)) return notify_fail("没有柴刀怎么砍柴？\n");
	if (query_temp("times")==0) return notify_fail("请适量砍伐！\n");
	if(me->query("qi")<20) return notify_fail("你的气太虚弱，不能砍柴！\n");
	ob=new(__DIR__"obj/chai");
	ob->move(environment(me));
	me->receive_damage("qi", 20);
	add_temp("times",-1);
	message_vision("$N砍了一捆柴，累得够呛。\n" , me);
	return 1;
}
