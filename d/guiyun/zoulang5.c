// Room: /d/guiyun/zoulang5.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short","走廊");
	set("long",@LONG
这是从中厅通向练武场的走廊。长长的走廊曲曲折折，雕栏画柱，
彩绘镂空，满目绿意，两旁种满了花树。
LONG );
	set("exits",([
		"east"  : __DIR__"zoulang4",
		"south" : __DIR__"zoulang6",
	]) );
	set("no_clean_up",0);
	set("outdoors", "guiyun");
	setup();
	replace_program(ROOM);
}
