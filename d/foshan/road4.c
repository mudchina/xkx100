//Room: /d/foshan/road4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","林间道");
	set("long",@LONG
这里是一条林间小道，在树丛中蜿蜒。这里是广西了。岭南山
林茂密，多产毒虫，各位行路要十分小心。
LONG);
	set("objects", ([
	   __DIR__"npc/snake": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "southwest" : __DIR__"road3",
	    "southeast" : __DIR__"road5",
	]));
	set("coor/x", -25000);
	set("coor/y", -6000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
