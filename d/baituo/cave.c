// Room: /d/baituo/cave.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short","岩洞");
	set("long", @LONG
这里是大岩洞，它是在『白驼山』特殊的地质条件下经过漫长的年代
形成的。南边是青竹林。再往北走就进洞了。
LONG	);
	set("exits",([
		"north"     : __DIR__"cave1",
		"southdown" : __DIR__"zhulin",
	]));
	set("objects",([
		__DIR__"npc/mangshe" : 1,
	]));
	set("outdoors","baituo");
	set("coor/x", -50040);
	set("coor/y", 20070);
	set("coor/z", 40);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir =="north" )
	{
		if (objectp(present("mang she", environment(me))))
			return notify_fail("蟒蛇挡住你的去路！\n");
	}
	return ::valid_leave(me, dir);
}


