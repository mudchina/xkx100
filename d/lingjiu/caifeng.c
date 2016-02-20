//ROOM: caifeng.c

inherit ROOM;

void create()
{
	set("short", "潇湘馆");
	set("long",@LONG
这是『灵鹫宫』的裁缝室。几个女子围坐在一块，飞针走线，苦练
女红，难道她们是为了以后找一个好婆家吗？ 
LONG );
	set("exits", ([
		"south" : __DIR__"changl10",
	]));
	set("objects",([
		__DIR__"npc/fumy" : 1,
	]));
	set("coor/x", -50980);
	set("coor/y", 30170);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}