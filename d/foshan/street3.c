//Room: /d/foshan/street3.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","佛山镇街");
	set("long",@LONG
佛山自古与朱仙、景德、汉口并称天下四大镇，端的是民丰物
阜，市廛繁华。一条大街横亘东西。南边是南门，通往南海。北边
出北门跨南岭可达中原。
LONG);
	set("objects", ([
	    "/d/city/npc/liumangtou": 1,
	]));
	set("outdoors", "foshan");
	set("exits",([ /* sizeof() == 1 */
	    "north" : __DIR__"northgate",
	    "south" : __DIR__"southgate",
	    "west"  : __DIR__"street2",
	    "east"  : __DIR__"street4",
	]));
	set("coor/x", -1400);
	set("coor/y", -6600);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
