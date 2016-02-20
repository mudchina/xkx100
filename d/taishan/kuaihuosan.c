// Room: /d/taishan/kuaihuosan.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "快活三");
	set("long", @LONG
快活三里在中天门北，又名快活山。登山至此，忽逢坦途，青山四
围，下临绝涧，气爽景幽。南侧有名泉，武中奇题“玉液泉”，水甚甘
冽。
LONG );
	set("exits", ([
		"north" : __DIR__"yunbu",
		"south" : __DIR__"ertian",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 390);
	set("coor/y", 670);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
