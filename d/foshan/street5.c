//Room: /d/foshan/street5.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","佛山镇街");
	set("long",@LONG
佛山镇街东西相连。东边是镇东门，南面一堵高墙，墙后便是
凤天南开的“英雄典当”。
LONG);
	set("objects", ([
	    __DIR__"npc/wolfdog": 1,
	    __DIR__"npc/jiading": 2,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "south" : __DIR__"dangpu",
	    "west"  : __DIR__"street4",
	    "east"  : __DIR__"eastgate",
	]));
	set("coor/x", -1290);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
