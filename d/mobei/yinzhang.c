// Room: /d/mobei/yinzhang.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "铁木真营帐");
	set("long", @LONG
蒙古人以游牧为生，赶了牲口东迁西徙，追逐水草，并无定居，用
毛毡搭搭成帐篷以蔽风雪，就叫做蒙古包。这虽然是铁木真的住处，却
依然质朴无华，只是比寻常所用大了数倍不止。
LONG);
	set("valid_startroom",1);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/tiemuzhen" : 1,
	]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"road",
	]));
	set("coor/x", -210);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
