// Room: /d/mobei/maowu.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "小茅屋");
	set("long", @LONG
几根粗糙的木头搭起一个架子，上面的树皮都还没剥落。塞北草原
长长的茅草覆盖在木头上，组成这个小茅屋。里面的一切都是江南模式，
用木头草草搭起的床，一边是个泥土灶，一边的墙上还开了个小窗。
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/liping" : 1,
	]));
	set("exits", ([ /* sizeof() == 1 */
		"out" : __DIR__"caodui",
	]));
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 5160);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
