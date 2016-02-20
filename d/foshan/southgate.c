//Room: /d/foshan/southgate.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","佛山南门");
	set("long",@LONG
这里是佛山镇的南门。出南门向南，就到达南海之滨了。北面
一条东西向的大街是佛山镇的主要街道。
LONG);
	set("objects", ([
//	   __DIR__"npc/puren": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"street3",
	    "south"  : "/d/xiakedao/xkroad3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1400);
	set("coor/y", -7000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
