//Room: /d/dali/gudao.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","古道");
	set("long",@LONG
一条石板古道，两边树木苍翠，山势平缓，南面是一望无际的西
双版纳大森林。大道北面有一片宏伟建筑，一堵里许长的红墙隔开，
越过墙头可见一座高楼耸立，正是大理名胜五华楼。
LONG);
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "enter"   : __DIR__"dating",
	    "west"    : __DIR__"shanlu6",
	    "east"    : __DIR__"luyuxi",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50000);
	set("coor/y", -75000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}