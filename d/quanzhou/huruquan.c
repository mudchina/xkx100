// Room: /d/quanzhou/huruquan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "虎乳泉");
	set("long", @LONG
这是一块斜卧着的石皮，有泉水从缝隙中迸出，流入一个尺余见方
的石孔中。它流了不知多少岁月了，但从来不涸。水清洌见底，甘甜似
乳，用它泡茶，香味沁人心脾。泉州及清源山得名「泉山」，皆源于此
泉。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown" : __DIR__"shanlu2",
		"northup"   : __DIR__"qingyuandong",
	]));
	set("coor/x", 1840);
	set("coor/y", -6390);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
