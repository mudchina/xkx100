// shandong1.c
// Modified by Java Apr.27 1998

inherit ROOM;
void create()
{
        set("short","山洞");
        set("long",@LONG
空空荡荡一个山洞，倒也还算干净，尽头摆了一张石床。
LONG );
        set("exits",([
                "out" : __DIR__"sroad8",
        ]));
        set("objects", ([
                __DIR__"npc/shuisheng" :1,
                __DIR__"obj/dachang" :1,
                "/clone/medicine/vegetable/zanghonghua" : random(2),
        ]));
	set("coor/x", -110000);
	set("coor/y", -60010);
	set("coor/z", 200);
	setup();
        replace_program(ROOM);
}