// Room: /d/huijiang/bingqi.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "兵器库");
	set("long",@LONG
这里是红花会的兵器库，一捆捆的兵器堆得海了。清兵屡次进犯回
疆，交战频仍，这里很多兵器都是万里迢迢外的中原麻烦清兵带来的。
LONG );
        set("objects", ([
		WEAPON_DIR"zhujian"     : random(2)+1,
		WEAPON_DIR"zhubang"     : random(2)+1,
		WEAPON_DIR"blade/mudao" : random(2)+1,
		__DIR__"obj/feidao"     : random(2)+1,
        ]));
	set("exits", ([
		"west" : __DIR__"wuchang",
	]));
	set("coor/x", -50030);
	set("coor/y", 9140);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
