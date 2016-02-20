// Room: /d/wuxi/shuyuangate.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "书院门楼");
	set("long", @LONG
东林书院环境幽雅，两面临河，小桥流水，垂柳依依，书声琅琅。
一座高大的石牌坊(fang)矗立在前，两棵古柏直冲云霄。再向里走就是
书院的学堂，学堂门口挂着一幅对联(lian)。两侧是碧碧池水，看了后
顿觉赏心悦目。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"shuyuan",
		"south" : __DIR__"eastroad2",
	]));
	set("item_desc", ([
		"lian" : "
  风声雨声读书声 声声入耳
  家事国事天下事 事事关心\n",
		"fang" : "
 前刻后学津梁后镌后学津梁\n",
	]));
	set("coor/x", 390);
	set("coor/y", -790);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

