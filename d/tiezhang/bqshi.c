// Room: /d/tiezhang/bqshi.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "兵器室");
	set("long", @LONG
铁掌帮虽是以掌法、轻功著称，但帮中仍存有大量的兵器。以供武
功不够的帮众使用。屋内两侧排列的都是兵器架，架上面刀、枪、剑、
戟、斧、钺、钩、叉应有尽有。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
		"south" : __DIR__"zoulang1",
	]));
	set("objects", ([ /* sizeof() == 4 */
		WEAPON_DIR+"gangdao" : 1,
		WEAPON_DIR+"gangjian" : 1,
		WEAPON_DIR+"gangzhang" : 1,
		WEAPON_DIR+"changbian" : 1,
		WEAPON_DIR+"spear/changqiang" : 1,
		WEAPON_DIR+"spear/muqiang" : 1,
		WEAPON_DIR+"spear/tieqiang" : 1,
	]));

	set("coor/x", -2030);
	set("coor/y", -1950);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}




