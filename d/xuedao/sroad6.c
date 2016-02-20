// sroad6.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","大雪山口");
        set("long",@LONG
冰天雪地，寒风刺骨。不是内力高深的人，已然经受不住了。
LONG );
        set("exits",([
                "northdown" : __DIR__"sroad5",
                "westup"    : __DIR__"sroad7",
        ]));
        set("objects", ([
                "/clone/medicine/vegetable/zanghonghua" : random(2),
        ]));
        set("outdoors", "xueshan");
	set("coor/x", -100000);
	set("coor/y", -50000);
	set("coor/z", 300);
	setup();
	replace_program(ROOM);
}