//Room: /d/dali/chahua3.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","茶花园");
	set("long",@LONG
大理茶花冠绝天下，镇南王府的茶花自然更非凡品。你正走在茶
花园中，层层密密的都是争奇斗妍的茶花。靠南岸边一溜的盆栽的茶
花，微风从水面吹来，摇曳婆娑。
LONG);
	set("objects", ([
	   __DIR__"obj/chahua8": 1,
	   __DIR__"obj/chahua9": 1,
	   __DIR__"obj/chahua10": 1,
	]));
	set("outdoors", "daliwang");
	set("exits",([ /* sizeof() == 1 */
	    "southwest"  : __DIR__"chahua2",
	    "north"      : __DIR__"chahua6",
	    "southeast"  : __DIR__"chahua5",
	]));
	set("coor/x", -38950);
	set("coor/y", -69990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}