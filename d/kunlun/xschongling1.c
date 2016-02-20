// Room: /d/kunlun/xschongling1.c
// Last Modified by winder on Jun. 29 2001

inherit ROOM;

void create()
{
	set("short", "雪山丛林");
	set("long", @LONG
这是一个很大的丛林，树木枝叶上挂满了冰雪，雪白的一大片，奇
美无比。丛林向山上延伸，直至山顶。在丛林中微露出一条小道，依稀
可认，你走在小道上，雪地中留下一行长长的足印。
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"westup"    : __DIR__"xuanya",
		"southdown" : __DIR__"xschongling",
	]));
	set("no_clean_up", 0);
	set("outdoors", "hongmei");
	set("coor/x", -90050);
	set("coor/y", 20010);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
