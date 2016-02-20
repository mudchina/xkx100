// Room: /d/taohuacun/taohua1.c

inherit ROOM;

void create()
{
	set("short", "桃花林");
	set("long", @LONG
这是一片烂漫的桃花林，满山遍野的桃树枝上，开着桃红的桃
花。桃花上头，飞满了细细嗡嗡的不甘寂寞的蜜蜂。脚下是一条不
宽也不窄的林间小道，道边是密密丛丛的嫩草和争奇斗艳的小花。
LONG );
	set("outdoors", "taohuacun");
//	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"taohua2",
		"south" : "/d/city/ximen",
		"west"  : "/d/5lt/exit",
	]));
	set("objects", ([
		"/d/wudang/npc/bee" : 1,
	]));
	set("coor/x", -100);
	set("coor/y", 0);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}