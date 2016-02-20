// Room: /d/wuyi/tongxianjing.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "通仙井");
	set("long", @LONG
通仙井位于御茶园内，又名呼来泉。井水清冽甘甜，为制茶的上等
好水，号称武夷山第一井。诗曰：“石乳沾余润，云根石髓流。玉瓯浮
动处，神人洞天游。”
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"yuchayuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1390);
	set("coor/y", -5020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

