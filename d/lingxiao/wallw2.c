// Room: /d/lingxiao/wallw2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "城头");
	set("long", @LONG 
高处不胜寒。不只是雪，连霜也纷纷而下。头天晚上还是石城木垛，
一下子就霜雪漫天，万物俱白。古诗云“天涯霜雪霁寒霄”。大概也就
是这个意思吧。
LONG );
	set("outdoors", "lingxiao");
	set("exits", ([
		"west" : __DIR__"wallw3",
		"east" : __DIR__"wallw1",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	])); 
	set("coor/x", -31020);
	set("coor/y", -8930);
	set("coor/z", 150);
	setup(); 
	replace_program(ROOM);
}

