//Room: /d/dali/chahuashan3.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","茶花山");
	set("long",@LONG
你走在茶花山上，这里遍地是生长茂盛的茶花。当然，大部
分是凡品，但偶尔也会有一两株佳品藏匿其中。西望不远是大理
城的北门。有一些毒蜂在飞来飞去，似乎毒蜂巢(fengchao)就在
附近茶花丛里。
LONG);
	set("objects", ([
	   __DIR__"npc/bee": 3,
	]));
	set("item_desc", ([
	   "fengchao" : "这是一个野毒蜂的蜂巢。\n",
	]));
	set("outdoors", "dalic");
	set("exits",([ /* sizeof() == 1 */
	    "south"     : __DIR__"chahuashan2",
	]));
	set("coor/x", -38900);
	set("coor/y", -69900);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}