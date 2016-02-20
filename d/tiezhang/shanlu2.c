// Room: /d/tiezhang/shanlu2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
你走在一条崎岖的山路上，道旁山峰壁立，长草过腰，中间一条羊
肠小路，仅容一人勉强过去。
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"guangchang",
		"south" : __DIR__"shanlu1",
	]));
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 3 */
		__DIR__"npc/huiyi" : 2,
	]));
	set("outdoors", "tiezhang");

	set("coor/x", -2040);
	set("coor/y", -1980);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}