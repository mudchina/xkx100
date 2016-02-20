// wg_houyuan3.c

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这里是后院外了，四周都是菜地，往北是个小山坡，东西面都是用
篱笆围起的菜地，种着各样的菜，篱笆很破烂，摇摇欲坠，看来这里没
什么人打理。
LONG);
	set("exits", ([
		"north" : __DIR__"wg_caidi2",
		"south" : __DIR__"wg_caidi1",
		"west" : __DIR__"wg_houyuan2",
	]));
	set("objects", ([	    
		__DIR__"npc/wg_ryjdizi" : 1,
		__DIR__"npc/wg_baituodizi" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 81);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

