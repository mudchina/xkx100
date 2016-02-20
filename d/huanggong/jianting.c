// Room: /d/huanggong/jianting.c

inherit ROOM;

void create()
{
	set("short", "紫禁箭亭");
	set("long", @LONG
在一大片空地上有一座箭亭, 又称紫禁箭亭, 皇上常在这和王公大
臣们一齐射箭, 操练武艺.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 6 */
		"north" : __DIR__"huangjimen",
		"south" : __DIR__"yushanfang",
		"west"  : __DIR__"jingyunmen",
		"east"  : __DIR__"dao3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -180);
	set("coor/y", 5270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}