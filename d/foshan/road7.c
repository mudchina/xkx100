//Room: /d/foshan/road7.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","林间道");
	set("long",@LONG
这里是一条林间小道，在树丛中蜿蜒。东面是岭南重镇佛山，
西边通向广西。
LONG);
	set("objects", ([
	   __DIR__"obj/shuzhi": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "west" : __DIR__"road6",
	    "east" : __DIR__"westgate",
	]));
	set("coor/x", -10000);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
