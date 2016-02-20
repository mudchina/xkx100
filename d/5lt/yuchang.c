// Room: /d/5lt/yuchang.c

inherit ROOM;
int do_jump(string arg);

void create()
{
	set("short", "海滨浴场");
	set("long", @LONG
这是一个非常干净的海滨浴场，每到夏季这里就变成全村最热闹的地
方，在这儿可以深海潜水、出海钓鱼、冲浪和游泳。海边的码头(pier)
还可以看到一艘豪华游艇。
LONG);
	set("outdoors", "5lt");
	set("exits", ([
		"east"  : __DIR__"haitan",
	]));
	set("objects",  ([
		__DIR__"npc/sunray": 1,
	]));
	set("no_fight", "1");
	set("coor/x", -205);
	set("coor/y", 20);
	set("coor/z", 0);
	setup();
}