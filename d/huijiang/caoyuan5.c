// Room: /d/huijiang/caoyuan5.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "草原");
	set("long", @LONG
这里就是人迹罕至的大草原，一望无际的草地随风波动，天地交接
处有几个黑点，四周非常的安静，只是不时有牧女清亮的歌声不知从哪
儿飘渺的传来.
LONG );
	set("outdoors", "huijiang");
	set("exits", ([
		"north" : __DIR__"caoyuan6",
		"south" : __DIR__"caoyuan4",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50050);
	set("coor/y", 9110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
