// Room: /d/mobei/damo.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "大漠");
	set ("long", @LONG
四周是一望无际的沙漠，在烈日的照射下，你几乎要虚脱了。西北
通向蒙古草原，南边则是京城方向。
LONG);
	set("no_clean_up", 0);
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 3 */
		"south"     : __DIR__"lvzhou",
		"northwest" : __DIR__"mobei",
	]));
	set("coor/x", -210);
	set("coor/y", 5130);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
