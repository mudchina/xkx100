//Room: /d/dali/chahua8.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","花园后门");
	set("long",@LONG
大理茶花冠绝天下，镇南王府的茶花自然更非凡品。你站在茶花
园后门口，对着满园春色，不禁大喜过望。东边就进园了，西面是一
条石铺甬道。
LONG);
	set("outdoors", "daliwang");
	set("exits",([ /* sizeof() == 1 */
	    "east"   : __DIR__"chahua7",
	    "west"   : __DIR__"yongdao2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -38960);
	set("coor/y", -69970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}