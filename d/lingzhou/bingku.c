// Room: /d/lingzhou/bingku.c

inherit ROOM;

void create()
{
	set("short", "冰窟");
	set("long", @LONG
这里是皇宫里储藏食物的所在，上下三层，到处整齐的码着巨大的
冰块。平时决无人来，只有夏天的时候御膳房的人偶来光顾。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"north" : __DIR__"yushanfang",
	]));
	set("no_clean_up", 0);

	set("coor/x", -17955);
	set("coor/y", 32103);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
