// Room: /d/huijiang/fangju.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "防具库");
	set("long",@LONG
这里是红花会的防具库。红花会为了反清复明，做了很多物质上的
准备。看看这里，你大概就能有所体会。整间仓库堆到顶，都是满满当
当的，所有防具真是应有尽有。
LONG );
        set("objects", ([
		ARMOR_DIR"beixin"  : random(2)+1,
		ARMOR_DIR"tengjia" : random(2)+1,
		ARMOR_DIR"tiejia"  : random(2)+1,
		ARMOR_DIR"niupi"   : random(2)+1,
        ]));
	set("exits", ([
		"south" : __DIR__"wuchang",
	]));
	set("coor/x", -50040);
	set("coor/y", 9150);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
