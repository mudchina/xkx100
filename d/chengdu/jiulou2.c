// Room: /d/chengdu/jiulou2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "银杏酒楼二楼");
	set("long", @LONG
你坐在成都最豪华的酒楼上，看着楼下的凡人忙忙碌碌，心情很是
愉快，所谓“对酒当歌，人生几何”，还犹豫什么，尽情享受生活吧！
LONG );
	set("exits", ([
		"down" : __DIR__"jiulou1",
	]));
	set("objects", ([
		  __DIR__"obj/chair" : 4,
	]));
	set("coor/x", -8030);
	set("coor/y", -3020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
