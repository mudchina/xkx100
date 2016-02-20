// Room: /d/huashan/luoyan.c
// Last Modified by winder on Aug. 1 2002

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "落雁峰");
	set("long", @LONG
南峰又名落雁峰，是华山最高峰。峰头题刻极多，如“太华峰头”、
“竣极于天”、“袖拂天星”等，极言华岳之高。环顾四周，皆在足下。
寇准诗赞曰：只有天在上，更无山与齐；举头红日近，回首白云低。传
说五代时候的隐士陈抟就隐居在这里。宋太祖曾经下诏征他出山作官，
他便在这里写下谢诏表说：“一片野心都被白云锁住，九重宠诏休教丹
凤衔来”，表示不愿出山做官。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"enter"     : __DIR__"xiaofang",
		"northdown" : __DIR__"zhandao",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huashan");
	set("coor/x", -860);
	set("coor/y", 120);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}
