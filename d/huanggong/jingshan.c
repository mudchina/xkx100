// Room: /d/huanggong/jingshan.c

inherit ROOM;

void create()
{
	set("short", "景山");
	set("long", @LONG
此地又名煤山, 万寿山, 是一片风景秀丽的皇家园林. 在幽静的松
柏林中, 一片郁郁葱葱的喜人绿意, 显得苍老和雄劲, 也含蕴着无限的
妩媚风光. 在山的东麓有一株槐树, 即为崇祯帝死难处.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"shenwumen",
		"north" : "/d/beijing/hbridge",
	]));
	set("no_clean_up", 0);

	set("coor/x", -250);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
