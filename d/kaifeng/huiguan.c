// /kaifeng/huiguan.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "山陕甘会馆");
	set("long", @LONG
山陕甘会馆是山西，陕西，甘肃的富商巨贾建造的，是旅汴同乡聚
会的场所，就是给这三地的人聚会的。当然也有在此来商谈生意的。里
面就是关帝庙。
LONG);
	set("exits", ([
		"west" : __DIR__"eroad2",
		"east" : __DIR__"paifang",
	]));
	set("objects", ([
		__DIR__"npc/walker" : 1,
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
