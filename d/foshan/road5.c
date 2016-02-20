//Room: /d/foshan/road5.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","林间道");
	set("long",@LONG
这里是一条林间小道，在树丛中蜿蜒。这里是广西了。岭南山
林茂密，多产毒虫，各位行路要十分小心。
LONG);
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "east"      : __DIR__"road6",
	    "northwest" : __DIR__"road4",
	]));
        set("objects", ([
                "/clone/medicine/vegetable/chuanshanjia" : random(2),
        ]));
	set("coor/x", -20000);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
