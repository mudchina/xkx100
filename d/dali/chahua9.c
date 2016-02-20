//Room: /d/dali/chahua9.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","茶花园");
	set("long",@LONG
大理茶花冠绝天下，镇南王府的茶花自然更非凡品。你站在茶花
园的最高处，低头看去，满园春色，尽在目下。西望亭台楼阁，错落
有秩。
LONG);
	set("objects", ([
	   __DIR__"obj/chahua7": 1,
	   __DIR__"npc/muwanqing": 1,
	]));
	set("outdoors", "daliwang");
	set("exits",([ /* sizeof() == 1 */
	    "southdown"  : __DIR__"chahua7",
	]));
	set("coor/x", -38950);
	set("coor/y", -69960);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}