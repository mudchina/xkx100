// Room: /d/huijiang/zoulang.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long",@LONG
你走在一条长长的走廊上，四周静悄悄的，你的脚步声传得很远。
两旁池塘里的残荷上停了几只呱呱乱叫的青蛙，阵阵轻风吹来，令人欲
醉。
LONG );
	set("outdoors", "huijiang");	
        set("objects", ([
                __DIR__"npc/xinyan" : 1,
        ]));
	set("exits", ([
		"westup" : __DIR__"zoulang2",
		"eastup" : __DIR__"zoulang3",
		"out"    : __DIR__"damen",
	]));
	set("coor/x", -50060);
	set("coor/y", 9140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
