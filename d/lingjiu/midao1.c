// midao1.c

inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
你的眼前是一条用汉白玉铺成的台阶，一直向下延伸，两边的墙壁
都是花岗岩，墙上隔十来步就有一盏油灯，使你能看清周围。
LONG );
	set("exits", ([
		"up" : __DIR__"huayuan",
		"northdown": __DIR__"midao2",
	]));
	set("objects",([
		__DIR__"npc/nvlang" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -51000);
	set("coor/y", 30150);
	set("coor/z", 50);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( (dir == "northdown") &&
		((string)me->query("family/family_name") != "逍遥派") &&
		((string)me->query("family/family_name") != "灵鹫宫") &&
		objectp(present("nv lang", environment(me))) )
		return notify_fail("蒙面女郎伸手拦住你，说道：“对不起，本门重地，请回！”\n");
	return ::valid_leave(me, dir);
}