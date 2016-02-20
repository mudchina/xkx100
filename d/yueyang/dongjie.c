// Room: /d/yueyang/dongjie.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "东街");
	set("long", @LONG
这是一条又长又宽的青石大道，打扫得十分干净。屋檐下，偶有小
孩淘气撒尿，立马就给大人拎着耳朵拖走。原来，北边就是府衙，西边
虽然喧闹，这条街却十分安静。南边是一个茶馆。来来往往的客商常去
歇脚，而公人也时有前去饮茶纳凉的。
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"zhongxin",
		"south" : __DIR__"chaguan",
		"north" : __DIR__"yamen",
	]));
	set("objects", ([
		__DIR__"npc/liumang" : 1,
	]));
	set("coor/x", -1400);
	set("coor/y", -2270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
