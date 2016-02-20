// /d/xingxiu/nanjiang.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	set("short", "南疆沙漠");
	set("long", @LONG
这就是浩瀚的塔克拉马干大沙漠，一走进来，你仿佛迷失了方向。
你感到口内十分焦渴，还是快些离开吧。
LONG );

	set("outdoors", "xiyu");
	set("exits", ([
		"northeast" : __DIR__"silk5",
		"southeast" : __FILE__,
		"southwest" : __FILE__,
		"northwest" : __DIR__"nanjiang1",
		"north"     : __FILE__,
		"south"     : __FILE__,
		"west"      : __FILE__,
		"east"      : __FILE__,
	]));
	set("no_clean_up", 0);
	set("coor/x", -41010);
	set("coor/y", 8990);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	int current_water;

	current_water = me->query("water");
	if (current_water==0&&userp(me))
	{
		write("你已经感到不行了，冥冥中你觉得有人把你抬到天山脚下。\n");
		me->move(__DIR__"shanjiao");
		me->unconcious();
	}

	if (current_water>0 && current_water<=20&&userp(me))
	{
		   write("你过于缺水，眼冒金星。\n");
		   me->set("water",0);
	}

	if (current_water>20&&userp(me))
	{	
		me->set("water",current_water-20);
	}
	if (dir=="east" || dir=="south" || dir=="west" || dir=="north") 
		return notify_fail("你向那边走去，结果发现那是沙漠中的海市蜃楼。\n");
	return ::valid_leave(me, dir);
}

