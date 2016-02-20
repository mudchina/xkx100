//Room: /d/dali/baiyiminju.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","摆夷民居");
	set("long",@LONG
摆夷是大理第一大族，大多散布在苍山洱海附近。摆夷民居是以
石块垒成，别具风格。朝花节那天，家家户户都把盆栽花木摆在门口，
摆搭成一座座的“花山”，招引四野乡村的人来观花街。
LONG);
	set("objects", ([
	   __DIR__"npc/oldman": 1,
	   __DIR__"npc/girl1": 2,
	]));
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"dahejieeast",
	]));
	set("coor/x", -39900);
	set("coor/y", -71040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}