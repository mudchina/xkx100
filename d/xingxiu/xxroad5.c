// Room: /d/xingxiu/xxroad5.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
山势在这里渐渐变得平缓，你已经可以听见西边山涧底的水声。东
面有一个山洞。
LONG );
	set("exits", ([
		"south" : __DIR__"xxroad4",
		"enter" : __DIR__"cangku",
		"north" : __DIR__"xxroad6",
	]));
	set("objects", ([
		CLASS_D("xingxiu")+"/chuchen" : 1,
	]) );
//	set("no_clean_up", 0);
	set("outdoors", "xingxiu");
	set("coor/x", -51000);
	set("coor/y", 20120);
	set("coor/z", 30);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "星宿派") &&
		dir != "south" && (present("chuchen zi", environment(me))))
	{
		say("出尘子一言不发，闪身拦在"+me->name()+"面前。\n");
		return notify_fail("出尘子一言不发，闪身拦在你面前。\n");
	}
	return ::valid_leave(me, dir);
}
