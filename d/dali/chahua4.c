//Room: /d/dali/chahua4.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","茶花园");
	set("long",@LONG
大理茶花冠绝天下，镇南王府的茶花自然更非凡品。你站在茶花
园中，北面是一片波光涟滟的湖面。靠岸的柳树下，有几盆茶花，娇
艳照人，在满园烂漫的茶花围中，仍骄然出群。
LONG);
	set("objects", ([
	   __DIR__"obj/chahua4": 1,
	]));
	set("outdoors", "daliwang");
	set("exits",([ /* sizeof() == 1 */
	    "northeast"  : __DIR__"chahua5",
	    "northwest"  : __DIR__"chahua2",
	]));
	set("coor/x", -38950);
	set("coor/y", -70010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}