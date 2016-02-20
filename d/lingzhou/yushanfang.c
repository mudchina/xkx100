// Room: /d/lingzhou/yushanfang.c

inherit ROOM;

void create()
{
	set("short", "御膳房");
	set("long", @LONG
这里是膳房，西厢房是两位江南名厨的住处，东厢房是膳房下手们
住的。北面是柴房。院子打扫的很干净，中间有一口水井。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		"west"  : __DIR__"huilang",
		"south" : __DIR__"bingku",
		"north" : __DIR__"chaifang",
	]));
	set("no_clean_up", 0);
	set("resource", ([ /* sizeof() == 1 */
		"water" : 1,
	]));
	set("coor/x", -17955);
	set("coor/y", 32106);
	set("coor/z", 0);

	setup();
	replace_program(ROOM);
}
