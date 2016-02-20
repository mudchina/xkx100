// Room: /d/yueyang/jiudian.c 
// Last Modifyed by Winder on Dec. 4 2001
inherit ROOM;

void create()
{
	set("short", "洞宾楼");
	set("long", @LONG
吕洞宾三醉洞庭的故事无人不知，这个洞宾楼便是仰慕当年神迹而
建。现在生意好了，也变成一座岳阳城最大的大酒楼了。凡来到岳阳的
人，如果说没有在洞宾楼喝过龟蛇酒，尝过洞庭鱼，也算是憾事了。
LONG );
	set("exits", ([
		"east"  : __DIR__"nanjie",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer2" : 1,
	]));
	set("coor/x", -1420);
	set("coor/y", -2280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
