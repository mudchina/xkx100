// Room: /d/baituo/caomeide.c
// Last Modified by winder on May. 15 2001

inherit ROOM;
void create()
{
	set("short","草莓地");
	set("long", @LONG
这里是一块草莓地，鲜红的草莓散落在绿草中，让人感到美妙惬
意。
LONG	);
	set("exits", ([
		"northeast" : __DIR__"shulin1",
	]));
	set("objects" , ([
		__DIR__"obj/caomei" : random(7),
	]));
	set("outdoors","baituo");
	set("coor/x", -50050);
	set("coor/y", 20010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
