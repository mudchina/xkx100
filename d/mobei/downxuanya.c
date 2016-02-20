// Room: /d/mobei/downxuanya.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "悬崖下");
	set("long", @LONG
陡峭的山崖壁立，漠北苦寒的风沙侵蚀，山崖更是光滑险峻。几柱
矮树平平从山石中伸出，铁灰色的山石愈行愈高，直与天空中的白云相
接。两头白色的大雕围绕着山崖边的一株松树鸣叫。
LONG);
	set("outdoors","mobei");
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/baidiao" : 2,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"xiaolu",
	]));
	set("coor/x", -250);
	set("coor/y", 5210);
	set("coor/z", 10);
	setup();
}

void init()
{
	add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}
int do_climb(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if( arg=="ya")
	{
		message("vision", me->name() + "吭吃吭吃向悬崖上爬去。\n", environment(me), ({me}) );
		me->move(__DIR__"yading");
		message("vision", me->name() + "从悬崖下爬了上来，粘了一身泥。\n", environment(me), me );
		return 1;
	}
}

