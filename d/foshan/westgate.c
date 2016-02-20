//Room: /d/foshan/westgate.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","佛山西门");
	set("long",@LONG
这里是佛山镇的西门。岭南以西经由广西可至大理。东面一条
东西向的大街是佛山镇的主要街道。
LONG);
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "east"  : __DIR__"street1",
	    "west"  : __DIR__"road7",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3000);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
