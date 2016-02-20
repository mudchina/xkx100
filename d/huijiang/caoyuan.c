// Room: /d/huijiang/caoyuan.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;

void create()
{
	set("short", "草原");
	set("long", @LONG
美丽的草原就在你的面前，成群的牛羊围绕在你身边，远处天地交
际处不时有大片的烟尘涌起，刹那间就塞满了天地，那是戈壁中时而出
现的龙卷风。
LONG
	);
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 4 */
		"southup" : __DIR__"xiepo",
		"north" : __DIR__"caoyuan1",
		"west" : __DIR__"caoyuan2",
		"east" : __DIR__"caoyuan3",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/huizhushaonv" : 1,
	]));
	set("coor/x", -50050);
	set("coor/y", 9080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
