//Room: /d/foshan/road14.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","林间道");
	set("long",@LONG
这里是一条林间小道，在树丛中蜿蜒。东面就是泉州城的西门
吊桥，向西南可达岭南广东。
LONG);
	set("objects", ([
	   __DIR__"obj/hua3": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "east"      : "/d/quanzhou/westbridge",
	    "southwest" : __DIR__"road13",
	]));
	set("coor/x", 1700);
	set("coor/y", -6530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
