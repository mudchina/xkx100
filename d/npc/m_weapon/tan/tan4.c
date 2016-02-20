//tan4.c

inherit ROOM;

void create()
{
	set("short", "嘉兴南湖 ");
	set("long",
		"这里是嘉兴南湖底，四周黑忽忽的，头顶上看不见一点亮光，身边的水流\n"
		"忽上忽下的涌动着。看起来是一处海眼。脚下似乎有一点亮光，也不知是些\n"
		"什么。周围一片死寂，似乎暗藏着层层杀机。\n"

	);
	set("exits", ([
		"up"   : __DIR__"tan2",	
		"down" : __DIR__"tan5",
		"southwest" : __DIR__"tan6",
		"northwest" : __DIR__"tan6",
		
	]));
	set("no_clean_up", 0);
	set("coor/x", -1510);
	set("coor/y", -1010);
	set("coor/z", -30);
	setup();
	replace_program(ROOM);
}
