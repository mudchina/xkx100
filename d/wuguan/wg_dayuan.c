// Last Modified by Sir on 9/17/2001
// wg_dayuan.c

inherit ROOM;

void create()
{
	set("short", "武馆大院");
	set("long", @LONG
这是个大院子，南西两边都是练武场，不少人在这里习武强身，这
里很吵，乱哄哄的，你看见不时有扛着东西的，挑着水的匆匆而过。
LONG);
	set("exits", ([
		"out"  : __DIR__"wg_guanmen",
		"east" : __DIR__"wg_dayuan2",
		"south" : __DIR__"wg_lang2",
		"north" : __DIR__"wg_lang1",
	]));
	set("objects", ([
		__DIR__"npc/wg_songshandizi" : 1,
		__DIR__"npc/wg_shenlongdizi" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 11);
	set("coor/y", -40);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


