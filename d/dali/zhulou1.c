//Room: /d/dali/zhulou1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","竹楼下");
	set("long",@LONG
台夷人喜居竹林深处，房舍自然少不了用竹子搭成，竹为梁，竹
为墙，竹楼建的相当精致。下层基本上只是四根柱子架空的，既可以
作兽圈，也为了防蛇。一架竹梯通向上层的房舍。
LONG);
	set("objects", ([
	   __DIR__"npc/cow": 1,
	]));
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "south"   : __DIR__"wuding",
	    "up"      : __DIR__"zhulou2",
	]));
	set("coor/x", -41010);
	set("coor/y", -79000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}