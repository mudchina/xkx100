// Room: /d/huanggong/rijing.c

inherit ROOM;

void create()
{
	set("short", "日精门");
	set("long", @LONG
日精门北边是南书房, 南边是祭孔处, 这里是皇帝经常出行坐轿的
地方.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 1 */
		"west" : __DIR__"qianqingmen",
		"east" : __DIR__"yuqinggong",
	]));
	set("no_clean_up", 0);

	set("coor/x", -200);
	set("coor/y", 5180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}