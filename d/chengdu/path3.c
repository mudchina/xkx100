// Room: path3.c
// Date: Feb.14 1998 by Java

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "潭边小路");
	set("long", @LONG
季节虽然已经是深秋，但日正当中的阳光，仍旧是十分炎热的。四
周是一片芙蓉树，远山隐在云雾之中，恍若迷离的美人，不远处有着，
一丛丛的树林，有一条溪流，沿着林旁蜿蜒流去。置身其中，让人有发
古之幽思，又享大自然之浪漫。
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
		"southwest"  : __DIR__"path4",
		"southeast"  : __DIR__"path2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8070);
	set("coor/y", -2960);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
