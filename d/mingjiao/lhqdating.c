//lhqdating.c
inherit ROOM;

void create()
{
	set("short", "烈火旗大厅");
	set("long", @LONG
这里是烈火旗的大厅，厅中红旗招展，刀枪映血，教众绛衣赤帽，
团团拥住烈火旗掌旗使辛然。
LONG);
	set("exits", ([
		"west" : __DIR__"lhqyuan",
	]));
	set("objects", ([
		__DIR__"npc/xinran": 1,
	]));
	set("coor/x", -52020);
	set("coor/y", 1000);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}