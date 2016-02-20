// Room: /d/tiezhang/sslu1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "碎石路");
	set("long", @LONG
你走在一条用碎石铺成的小路上。两旁山势低缓，长满了翠绿的毛
竹，阵阵微风吹过，耳旁便响起一片沙沙声。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"eastup"   : __DIR__"sslu2",
		"westdown" : __DIR__"pingtai",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2030);
	set("coor/y", -1910);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}

