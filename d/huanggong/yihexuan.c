// Room: /d/huanggong/yihexuan.c

inherit ROOM;

void create()
{
	set("short", "颐和轩");
	set("long", @LONG
这儿是乾隆帝阅览书籍和游玩的地方, 也是一座珍宝馆, 其中多是
从全国各地搜刮来的珠宝珍奇.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"west"  : __DIR__"yuhuayuan2",
		"south" : __DIR__"leshou",
	]));
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 5240);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}