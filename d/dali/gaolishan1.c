//Room: /d/dali/gaolishan1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","高黎山东坡");
	set("long",@LONG
这里是高黎山的东坡，向东俯视奔淌而过的东泸水，远远眺望跨
谷相对的碧罗雪山。此去再向西全是崇山峻岭，人烟稀少。山间林深
兽多，乌夷族的猎人经常进山打猎。
LONG);
	set("objects", ([
	   __DIR__"npc/shanyang": 1,
	]));
	set("outdoors", "daliw");
	set("exits",([ /* sizeof() == 1 */
	    "west"      : __DIR__"gaolishan2",
	    "eastdown"  : __DIR__"atoubu",
	]));
	set("coor/x", -90010);
	set("coor/y", -70020);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}