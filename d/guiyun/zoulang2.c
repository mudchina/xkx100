// Room: /d/guiyun/zoulang2.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short","走廊");
	set("long",@LONG
这是连接中厅与后厅的走廊。长长的走廊曲曲折折，雕栏画柱，彩
绘镂空，满目绿意，两旁种满了花树。北边有一间客房。
LONG );
	set("exits",([
		"east"  : __DIR__"zoulang1",
		"west"  : __DIR__"zoulang3",
		"north" : __DIR__"kefang",
	]) );
	set("outdoors", "guiyun");
	set("objects",([
		__DIR__"npc/zhuangding2" : 1,
	]));  
	setup();
	replace_program(ROOM);
}
