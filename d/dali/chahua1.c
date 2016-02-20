//Room: /d/dali/chahua1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","花园门");
	set("long",@LONG
大理茶花冠绝天下，镇南王府的茶花自然更非凡品。你站在茶花
园口，对着满园春色，不禁大喜过望。东边就进园了，北边是一个库
房。南边是一栋厢房。
LONG);
	set("outdoors", "daliwang");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"bingqiku",
	    "south"  : __DIR__"xiuxishi",
	    "east"   : __DIR__"chahua2",
	    "west"   : __DIR__"tingyuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -38970);
	set("coor/y", -70000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}