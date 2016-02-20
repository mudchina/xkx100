// /d/shenlong/shulin1 树林
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	int i;
	set("short", "树林");
	set("long", @LONG
树林里光线暗淡，只能听见头顶上传来一些鸟儿的啼鸣。偶尔从茂
密的叶间透过的一线光伴着落叶在飞舞。朽木腐烂的气味和身后传来蛇
虫爬行的声音使人不觉犹豫了前进的脚步。
LONG
	);
	i = random (3);
	switch (i)
	{
		case 0:
			set("objects", ([
				"/d/city/obj/shuzhi" : 1,
				"/d/jiaxing/npc/wuya" : 1,
			]));
			break;
		case 1:
			set("objects", ([
				"/d/city/obj/shuzhi" : 1,
				"/d/wudang/npc/yetu" : 1,
			]));
			break;
		case 2:
			set("objects", ([
				"/d/city/obj/shuzhi" : 1,
				"/d/shenlong/npc/snake" : 1,
			]));
			break;
	}
	set("exits", ([
		"west"    : __DIR__"tiandi2",
		"north"   : __DIR__"shulin2",
		"southup" : __DIR__"shangang",
	]));
	set("outdoors", "shenlong");

	setup();
	replace_program(ROOM);
}

