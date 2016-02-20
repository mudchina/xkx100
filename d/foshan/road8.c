//Room: /d/foshan/road8.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","林间道");
	set("long",@LONG
这里是一条林间小道，在树丛中蜿蜒。西面是岭南重镇佛山，
东边通向福建泉州。
LONG);
	set("objects", ([
	   __DIR__"npc/zhang": 1,
	   __DIR__"npc/zhangkang": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "west" : __DIR__"eastgate",
	    "east" : __DIR__"road9",
	]));
	set("coor/x", -1000);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
