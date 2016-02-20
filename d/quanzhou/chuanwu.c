// Room: /d/quanzhou/chuanwu.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "船坞");
	set("long", @LONG
这里是云集了全国最好的造船技师和工匠。一眼望去，满是已完工
和即将完工的各种用途，各种大小的木船。坞内人们忙忙碌碌，一片繁
忙景象。
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"west" : __DIR__"portroad4",
	]));
	set("objects", ([
		__DIR__"npc/kuli" : 1,
	]));
	set("coor/x", 1870);
	set("coor/y", -6620);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
