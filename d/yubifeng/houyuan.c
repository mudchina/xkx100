// /yubifeng/baozang.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @long
这是庄主平时练功的地方，在这绝顶寒峰，几乎寸草不生，只有几
棵苍松挺立在那里。院内有一张石桌和几张石凳。
long );
	set("exits", ([
		"south" : __DIR__"houting",
	]));
	set("no_clean_up", 0);
	set("coor/x", 6120);
	set("coor/y", 5210);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
