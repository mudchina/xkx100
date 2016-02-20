// Room: /d/mobei/hill1.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "荒山上");
	set("long", @LONG
稀疏的灌木，草丛。坡顶比较平缓，西北风一阵紧，一阵缓，北面
的一片乌云缓缓移动过来，昏黄的月光下几点磷火漂移不定。东面的草
丛中似乎有些东西在闪着白光。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/kezhene" : 1,
	]));
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 3 */
		"east"      : __DIR__"caocong",
		"northwest" : __DIR__"caocong1",
		"westdown"  : __DIR__"shulin",
	]));
	set("coor/x", -210);
	set("coor/y", 5230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
