// Room: /city/xixiang.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "财主西厢");
	set("long", @LONG
这是财主小姐的闺房，一股幽香扑面而来。一张绣榻放在墙角，垂
着细纱。小姐正躺在榻上，懒洋洋地一幅思春模样。看到你突然闯进来，
惊呆了。
LONG );
	set("exits", ([
		"east" : __DIR__"houyuan",
	]));
	set("objects", ([
		__DIR__"npc/yingying" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", -31);
	set("coor/y", -13);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}