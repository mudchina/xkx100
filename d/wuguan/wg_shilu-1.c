// wg_shilu-1.c

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
你走在一条石板路上，从这里往南是物品房，你看见有不少人手里
拿着各样的工具，从那边过来，北面是武馆大厅。
LONG);
	set("exits", ([
		"south"   : __DIR__"wg_wupinfang",
		"east"    : __DIR__"wg_xuetang",
		"west"    : __DIR__"wg_zhangfang",
		"northup" : __DIR__"wg_dating",
	]));
	set("objects", ([
		__DIR__"npc/wg_xiaojh" : 1,
		__DIR__"npc/wg_xiaoyaodizi" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 41);
	set("coor/y", -50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

