// wg_houyuan2.c

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这里仍然是后院，北面不时传来马嘶声，你看过去，那里是个马房，
南面屋子里也是吵吵的，好象是锯木头的声音。
LONG);
	set("exits", ([
		"north" : __DIR__"wg_mafang",
		"south" : __DIR__"wg_mufang",
		"west"  : __DIR__"wg_houyuan",
		"east"  : __DIR__"wg_houyuan3",
	]));
	set("objects", ([
		__DIR__"npc/wg_xueshandizi" : 1,
		__DIR__"npc/wg_honghuabangzhong" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 71);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

