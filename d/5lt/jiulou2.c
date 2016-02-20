// Room: /d/5lt/jiulou2.c

inherit ROOM;

void create()
{
	set("short", "悦华酒楼二楼");
	set("long", @LONG
你坐在村里最豪华的酒楼上，看着楼下的凡人忙忙碌碌，心情很是
愉快，所谓“对酒当歌，人生几何”，还犹豫什么，尽情享受生活吧！
LONG );
	set("exits", ([
		"down" : __DIR__"jiulou1",
	]));
	set("objects", ([
		  __DIR__"obj/chair" : 4,
	]));
	set("coor/x", -160);
	set("coor/y", -10);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
