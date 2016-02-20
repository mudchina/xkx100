// Room: tidujie.c
// Date: Feb.14 1998 by Java

inherit ROOM;
void create()
{
	set("short", "提督街");
	set("long", @LONG
提督街就是因为通往提督府而得名。这一带来往行人很少，做生意
的就更是绝迹了。提督大人好象有甚麽想不开的，派了好多兵在这里守
卫，连江湖人物都不敢轻率踏入。
LONG );
	set("outdoors", "chengdu");
	set("exits", ([
		"west"  : __DIR__"nanjie2",
		"north" : __DIR__"tidugate",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 3,
	]));
	set("coor/x", -8040);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
