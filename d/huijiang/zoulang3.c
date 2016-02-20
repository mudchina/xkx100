// Room: /d/huijiang/zoulang.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long",@LONG
你走在一条长长的走廊上，两旁池塘里的残荷上停了几只呱呱乱叫
的青蛙，阵阵轻风吹来，令人欲醉。北边是个大厨房，一阵阵的饭菜香
味飘了满走廊。
LONG );
	set("outdoors", "huijiang");	
        set("objects", ([
		CLASS_D("honghua")+"/first" : 1,
        ]));
	set("exits", ([
		"east"     : __DIR__"wuchang",
		"north"    : __DIR__"chufang",
		"south"    : __DIR__"qiufang",
		"westdown" : __DIR__"zoulang1",
	]));
	set("coor/x", -50050);
	set("coor/y", 9140);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
