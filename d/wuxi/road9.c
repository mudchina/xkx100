// Room: /d/wuxi/road9.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "乡间小道");
	set("long", @LONG
小道突然变得开阔了许多，两边的树也变得稀少了，可以直接看到
一望无际的田野。前面空出了一个很大的场子，原来，你已经来到了吴
民们敬仰的圣庙泰伯庙的门口了。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"east"   : __DIR__"road8",
		"west"   : __DIR__"taibomiao",
	]));
	set("objects", ([
		"/d/village/npc/dog" : 1,
	]));
	set("coor/x", 350);
	set("coor/y", -860);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}