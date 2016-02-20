// /kaifeng/xilou.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "戏楼");
	set("long", @LONG
一座木头粗粗搭起的高台，台的后端用大的帘子遮了起来那后头就
是戏子装扮上台的地方。由于是关帝庙的缘故，演的无非是桃园三结义、
单骑走千里、杯酒斩华雄等故事。
LONG);
	set("objects", ([
		__DIR__"npc/qingyi" : 1,
		__DIR__"npc/xiaosheng" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"paifang",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
