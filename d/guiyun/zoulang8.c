// Room: /d/guiyun/zoulang8.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short","走廊");
	set("long",@LONG
这是连接花厅与花园的走廊。长长的走廊曲曲折折，雕栏画柱，彩
绘镂空，满目绿意，两旁种满了花树。
LONG );
	set("exits",([
		"east"  : __DIR__"huating",
		"north" : __DIR__"zoulang9",
	]) );
	set("no_clean_up",0);
	set("outdoors", "guiyun");
	setup();
	replace_program(ROOM);
}
