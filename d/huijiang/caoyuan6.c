// Room: /d/huijiang/caoyun6.c
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
		"northwest" : __DIR__"xiagu",
		"south"     : __DIR__"caoyuan5",
	]));
	set("objects", ([
		CLASS_D("honghua")+"/wei-chunhua" : 1,
	]));
	set("coor/x", -50050);
	set("coor/y", 9120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
