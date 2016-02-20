// Room: /d/huanggong/leshou.c

inherit ROOM;

void create()
{
	set("short", "乐寿堂");
	set("long", @LONG
这里是太上皇赋诗, 祝寿的地方. 后来, 慈禧曾居住在此, 并在这
庆祝她的六十大寿, 下令用筹建海军的军费兴建颐和园, 耗银高达数千
万两.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		 "north" : __DIR__"yihexuan",
		 "south" : __DIR__"yangxin2",
	]));
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 5230);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}