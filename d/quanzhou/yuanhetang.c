// Room: /d/quanzhou/yuanhetang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "源和堂");
	set("long", @LONG
这是远近闻名的蜜饯制作铺，各色水果经过他们的加工后风味独特，
甜而不腻，咸而不过，酸而不涩，又可以长期保存，远销海内外。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"east"      : __DIR__"zhaiqu3",
		"northeast" : __DIR__"zhaiqu2",
	]));
	set("coor/x", 1830);
	set("coor/y", -6560);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
