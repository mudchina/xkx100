// Room: /d/huanggong/yuehua.c

inherit ROOM;

void create()
{
	set("short", "月华门");
	set("long", @LONG
月华门北边是批本处, 南边是奏事房, 这里是皇帝经常出行坐轿的
地方.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"qianqingmen",
		"west" : __DIR__"yangxin",
	]));
	set("no_clean_up", 0);

	set("coor/x", -210);
	set("coor/y", 5280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}