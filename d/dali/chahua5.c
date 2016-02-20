//Room: /d/dali/chahua5.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","茶花园");
	set("long",@LONG
大理茶花冠绝天下，镇南王府的茶花自然更非凡品。你站在茶花
园中，发现几朵娇嫩欲滴的茶花，你不禁多看了两眼。西面是一个小
湖，湖面碧绿如玉，暖风吹来，曛曛入醉。
LONG);
	set("objects", ([
	   __DIR__"obj/chahua11": 1,
	   __DIR__"obj/chahua12": 1,
	   __DIR__"obj/chahua13": 1,
	   __DIR__"npc/huanu": 1,
	]));
	set("outdoors", "daliwang");
	set("exits",([ /* sizeof() == 1 */
	    "northwest"  : __DIR__"chahua3",
	    "southwest"  : __DIR__"chahua4",
	]));
	set("coor/x", -38940);
	set("coor/y", -70000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}