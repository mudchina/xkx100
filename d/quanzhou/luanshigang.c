// Room: /d/quanzhou/luanshigang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "乱石岗");
	set("long", @LONG
这里树木阴森，砾石嶙峋，坡陡坑深，地势险要，历来是土匪盘据
的地方。
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"south" : __DIR__"shisun",
		"east"  : __DIR__"diaoqiao",
	]));
	set("objects", ([
		"/d/wudang/npc/tufei1" : 1,
		"/d/wudang/npc/tufei2" : 1,
		"/d/wudang/npc/tufeitou" : 1,
	]));
	set("coor/x", 1820);
	set("coor/y", -6580);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
