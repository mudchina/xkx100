inherit ROOM;

void create()
{
	set("short", "西四北大街");
	set("long", @LONG
这里是西四北大街。南边通往西单。东边通向地安门，北面是一间
书院。
LONG );
        set("outdoors", "beijing");
	set("exits", ([
		"east"  : __DIR__"di_an4",
		"south" : __DIR__"xisi",
		"north" : __DIR__"weifu_men",
	]));
	set("objects", ([
		"/d/taishan/npc/jian-ke": 1,
	]));
	set("coor/x", -220);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
