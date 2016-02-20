//Room: /d/dali/shanlu5.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","山路");
	set("long",@LONG
一条山路，两边是茂密的树林，西面是延绵不绝的大山，道路两
旁间或可见一些夷族的村镇。山路向南蜿蜒着。
LONG);
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "southeast"  : __DIR__"shanlu4",
	    "north"      : __DIR__"shanlu6",
	]));
	set("objects", ([
	   __DIR__"npc/wuliangdizi": 1,
	]));
	set("coor/x", -65000);
	set("coor/y", -78000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}