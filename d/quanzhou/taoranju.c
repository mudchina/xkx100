// Room: /d/quanzhou/taoranju.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "陶然茶居");
	set("long", @LONG
这是专供品尝和销售茶叶的店铺，店里清香四溢进门就有心旷神怡
之感。墙上有一价目表(sign)。
LONG );
	set("outdoors", "quanzhou");
	set("item_desc", ([
		"sign" : "
茶杯(Cha bei)                 ：三十文铜板
铁观音茶杯(Guanying chabei)   ：三十文铜板
龙井茶杯(Longjing chabei)     ：三十文铜板
茉莉花茶杯(Moli chabei)       ：三十文铜板
香片茶杯(Xiangpian chabei)    ：三十文铜板\n"
	]));
	set("exits", ([
		"south" : __DIR__"xinmenji",
	]));
	set("objects", ([
		__DIR__"npc/tao" : 1,
	]));
	set("coor/x", 1840);
	set("coor/y", -6570);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
