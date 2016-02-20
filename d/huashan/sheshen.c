// sheshenya.c
// Last Modified by winder on Aug. 1 2002

inherit ROOM;

void create()
{
	set("short", "舍身崖");
	set("long", @LONG
这是一段极窄极险的山崖，四周云雾飞绕，下面渊深无底。如不小
心，一失足掉下去，只怕连骨头都找不到。边上有个小山洞(dong)。
LONG );
	set("exits", ([ /* sizeof() == 1 */
		"eastdown" : __DIR__"canglong",
	]));
	set("item_desc", ([
		"dong" : "紧靠飞崖下石壁的小洞，黑呼呼的不知有多深。\n",
	]));
	set("objects",([
		__DIR__"npc/referee" : 1,
	]));
	set("outdoors", "huashan" );

	set("coor/x", -890);
	set("coor/y", 210);
	set("coor/z", 110);
	setup();
}

void init()
{
	object me = this_player();
	add_action("do_enter", "enter");
	add_action("do_enter", "zuan");
	if (me->query_temp("xunshan")) me->set_temp("xunshan/sheshen", 1);
	return;
}

int do_enter(string arg)
{
	object me = this_player();
	mapping fam;

	if( !arg || arg=="" ) return 0;
	if( arg=="dong" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "丐帮")
		{
			message("vision", me->name() + "运起丐帮缩骨功，一弯腰往洞里钻了进去。", environment(me), ({me}) );
			me->move("/d/gaibang/underhs");
			message("vision", me->name() + "从洞里走了进来。\n", environment(me), ({me}) );
			return 1;
		}
		else  return notify_fail("这么小的洞，你钻得进去吗？\n");
	}
}
