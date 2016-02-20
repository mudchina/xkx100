//tan7.c

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
		"up" : __DIR__"tan6",	
		"east" : __DIR__"tan5",
		"west" : __DIR__"tan7",
		"south" : __DIR__"tan7",
		"north" : __DIR__"tan7",
	]));
	set("objects" , ([
		__DIR__"npc/fish" : 3,
		__DIR__"item/zhenzhu" :1,	
	]) );
	set("coor/x", -1510);
	set("coor/y", -1000);
	set("coor/z", -40);
	setup();
	replace_program(ROOM);
}
