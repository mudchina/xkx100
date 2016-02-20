//room: liangong.c

inherit ROOM;

void create()
{
	set("short","戏凤阁");
	set("long",@LONG
这里是灵鹫宫弟子练功的地方。有几个妙龄女子正在专心致致地练
武，有几个手持竹剑,在互相拆招,身法灵动，犹如穿花蝴蝶一般，你不
禁看花了眼，别的人则坐在地上的蒲团上苦练内力。
LONG );
	set("exits",([
		"west" : __DIR__"changl4",
	]));
	set("objects",([
		"/d/shaolin/npc/mu-ren" : 5
	]));
	set("coor/x", -50970);
	set("coor/y", 30140);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}