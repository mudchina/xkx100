inherit ROOM;

void create()
{
	set("short", "西长安街");
	set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。往西望去，长长的
街道看不到头。东边就是天安门。一阵阵喝采声不时从北边的戏院传来。
南边就是京城最著名的‘回春堂’药店。
LONG );
        set("outdoors", "beijing");
	set("exits", ([
		"east"      : __DIR__"tian_anm",
		"west"      : __DIR__"xichang2",
		"south"     : __DIR__"huichunt",
		"north"     : __DIR__"xiyuan",
		"northeast" : "/d/beihai/ximen",
	]));
	set("objects", ([
		__DIR__"npc/flowerg": 1,
	]));
	set("coor/x", -210);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	me->delete_temp("warned");
	me->delete_temp("hastryup");
	return ::valid_leave(me, dir);
}
