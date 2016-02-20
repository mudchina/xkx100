// Room: /yixing/shulin4.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
树林里光线暗淡，只能听见头顶上传来一些鸟儿的啼鸣。偶尔从茂
密的叶间透过的一线光伴着落叶在飞舞。朽木腐烂的气味和身后传来野
兽的啸声使人不觉犹豫了前进的脚步。
LONG );
	set("outdoors", "yixing");
	set("exits", ([
		"west"  : __DIR__"shulin3",
		"south" : __DIR__"shanlu1",
		"north" : __DIR__"cldamen",
	]));
	set("objects", ([
		__DIR__"npc/dabei" : 1,
	]));
	set("coor/x", 230);
	set("coor/y", -170);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
