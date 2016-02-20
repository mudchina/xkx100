// ROOM lianjianshi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "炼剑场");
	set("long", @LONG
这里是玄兵古洞的炼剑场。四周荒凉没有人烟，地上隐约还能看见
斑斑的血迹，偶尔能看见的几棵树似乎也成了剑的表征，一个个剑拔弩
张的。露天放着一个巨大的炉子，冒着蓬蓬的蓝炎，激烈的罡气震得你
一阵晕眩，原来这里正在以内家真气炼剑。
LONG );
	set("exits", ([
		"south" : "/d/xingxiu/shamo3",
	]));
	set("objects",([
		__DIR__"npc/shijian" :1,
	]));
	set("coor/x", -30000);
	set("coor/y", 1030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
