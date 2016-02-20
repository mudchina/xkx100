inherit ROOM;

void create()
{
	set("short", "屠宰场");
	set("long", @LONG
这里是屠宰场，空气中弥漫着猪的气味。偶尔一阵热风吹过，顿时
一股臭气袭来，直熏得人作呕。一个中年人手握屠刀，指挥着伙计们杀
猪去毛。这就是京城最大的屠宰场，据说宫里所有的猪肉都是从这里送
去的。
LONG );
	set("exits", ([
		"east" : __DIR__"nandaj2",
	]));
	set("objects", ([
		CLASS_D("yunlong")+"/lilishi": 1,
		__DIR__"npc/huoji1": 2,
	]));
	set("coor/x", -210);
	set("coor/y", 4020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
