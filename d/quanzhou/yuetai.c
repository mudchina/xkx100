// Room: /d/quanzhou/yuetai.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "月台广场");
	set("long", @LONG
这是平坦光滑的石面广场，中间凸起一台面，面放置一焚吊炉。台
座边嵌着七十二幅狮身人面青石浮雕，有着浓厚的异国风味。东西各有
一座恢宏的石塔。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"dongta",
		"west"  : __DIR__"xita",
		"south" : __DIR__"dxbaodian",
		"north" : __DIR__"jietang",
	]));
	set("coor/x", 1830);
	set("coor/y", -6490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
