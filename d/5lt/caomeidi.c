// Room: /d/5lt/caomeidi.c

inherit ROOM;
void create()
{
	set("short","草莓地");
	set("long", @LONG
这里是一块草莓地，鲜红的草莓散落在绿草中，让人感到美妙惬
意。
LONG	);
	set("exits", ([
		"southeast" : __DIR__"fanshudi",
	]));
	set("objects" , ([
		__DIR__"obj/caomei" : random(10),
	]));
	set("outdoors","5lt");
	set("coor/x", -130);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
