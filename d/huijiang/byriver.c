// Room: /d/huijiang/byriver.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set ("short", "湖边");
	set ("long", @LONG
草原西端一座高山参天而起，耸入云霄。从山腰起全是皑皑白雪，
山腰以下却生满苍翠树木。树上小鸟鸣啾，湖中冰块撞击与瀑布声交织
成一片乐音。
LONG);
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"byriver1",
		"south" : __DIR__"xiaoxi2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50030);
	set("coor/y", 9020);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
