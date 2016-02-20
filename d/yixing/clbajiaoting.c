// /d/yixing/clbajiaoting.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

void create()
{
	set("short", "八角亭");
	set("long", @LONG
这是花园中一个小巧的亭子，供赏花时休息之用。亭中石桌石凳
俱全，石桌上还摆放着几盘点心。院中花卉暗香浮动。几个假山做得
甚是别致。
LONG );

	set("exits", ([
		"north" : __DIR__"clhuayuan",
		"west"  : __DIR__"clzoulang1",
	]));
	set("objects", ([
		__DIR__"npc/dingdang" : 1,
	]));
	set("outdoors", "yixing");
	setup();

	replace_program(ROOM);
}
