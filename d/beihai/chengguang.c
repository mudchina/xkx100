// /d/beihai/chengguan.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "承光殿");
	set("long", @LONG
这里是主殿承光殿，位于团城中央，是康熙时有元代仪天殿基础上
改建的。殿之方体结构为方形，重檐歇山顶，四面出抱厦，亦为歇山顶。
整个屋顶造型有如故宫之角楼状。整个建筑都用黄琉璃瓦，绿瓦剪边。
殿内供玉观音菩萨，雕琢精美洁白无暇，传为高宗时西藏之贡物。殿东
侧有一株高大苍劲的油松，树冠如盖，乾隆帝曾封为“遮阴侯”。
LONG
	);
	set("exits", ([
		"east"  : __DIR__"zhaojing",
		"west"  : __DIR__"yanxiang",
		"north" : __DIR__"jingji",
		"south" : __DIR__"yuweng",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -180);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
