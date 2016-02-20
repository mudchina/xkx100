//tan3.c

inherit ROOM;

void create()
{
	set("short", "嘉兴南湖 ");
	set("long",
		"这里是嘉兴南湖底，四周黑忽忽的，头顶上只能看见一点亮光，身边的水流\n"
		"似乎更加湍急了。脚下似乎有一点亮光，也不知是些什么。周围一片死寂，\n"
		"似乎暗藏着层层杀机。\n"

	);
	set("exits", ([
		"up" : __DIR__"tan2",
        "east" : __DIR__"tan6",
        "west" : __DIR__"tan4",
        "south" : __DIR__"tan5",
		"north" : __DIR__"tan6",
	]));
	set("no_clean_up", 0);
	set("coor/x", -1520);
	set("coor/y", -1010);
	set("coor/z", -30);
	setup();
	replace_program(ROOM);
}
