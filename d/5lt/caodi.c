// Room: /d/5lt/caodi.c

inherit ROOM;

void create()
{
	set("short", "草地");
	set("long", @LONG
一片平缓的草地一直沿山脚延伸，偶尔有些叫不出名目的大鸟小兽
在草丛中出没，十分自在地游嬉。
LONG);
	set("exits", ([
		"south"      : __DIR__"qsroad",
		"northwest"  : __DIR__"fanshudi",
		"eastup"     : __DIR__"shanlu",
	]));
        set("objects", ([
	]));
	set("coor/x", -120);
	set("coor/y", 10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}