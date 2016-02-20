// sroad5.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","大雪山口");
        set("long",@LONG
这儿遍地冰雪，你眼前白皑皑的一片。从东边爬上来的，心跳开始加速。
LONG );
        set("exits",([
                "eastdown"  : __DIR__"sroad4",
                "southup"   : __DIR__"sroad6",
        ]));
        set("objects", ([
                __DIR__"npc/xuebao" : random(2),
        ]));
        set("outdoors", "xueshan");
	set("coor/x", -100000);
	set("coor/y", -10000);
	set("coor/z", 200);
	setup();
	replace_program(ROOM);
}