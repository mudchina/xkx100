// Room: /yangzhou/kedian2.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "秦淮客寓二楼");
	set("long", @LONG
你正走在客寓二楼的走廊上，可以听到客房里不时地传来呼呼的
打鼾声，一阵高过一阵。不时有睡意朦胧的旅客进进出出，到楼下的
掌柜处付了钱再上来睡觉。
LONG );
	set("exits", ([
		"down"  : __DIR__"kedian",
		"enter" : __DIR__"kedian3",
	]));

	set("objects", ([
                CLASS_D("shaolin") + "/xingzhe" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", -20);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}