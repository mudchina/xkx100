// Room: /d/mobei/damo2.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set ("short", "大漠");
	set ("long", @LONG
四周是一望无际的沙漠，在烈日的照射下，你几乎要虚脱了。西北
通向蒙古草原，南边则是京城方向。
LONG);
	set("outdoors","mobei");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
		"southeast":__DIR__"huanglu1",
		"northwest":__DIR__"lvzhou",
	]));
	set("coor/x", -200);
	set("coor/y", 5110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
