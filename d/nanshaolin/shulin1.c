// Room: /d/nanshaolin/shulin1.c
// Last Modified by winder on May. 29 2001
// 这里也是去青云坪的地方。可是南少林可以不要。

inherit ROOM;

void create()
{
	set("short", "松树林");
	set("long", @LONG
这是一片松树林。几十丈高的大松树簇在一块，密实的枝叶象一蓬
蓬巨伞般伸向天空，把阳光遮得丝毫也无。尺把厚的松针积在地上，一
脚踩下去，半天拔不出来。
LONG );
	set("exits", ([
		"east"  : __FILE__,
		"west"  : __FILE__,
		"south" : __FILE__,
		"north" : __FILE__,
/*
		"east"  : __DIR__"shulin"+(random(10)+2),
		"west"  : __DIR__"shulin2",
		"south" : __DIR__"shanlu8",
		"north" : __DIR__"shulin"+(random(10)+2),
*/
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1840);
	set("coor/y", -6010);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}

