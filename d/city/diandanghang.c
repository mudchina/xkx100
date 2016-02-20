// Room: /city/diandanghang.c
// Last Modified by Winder on Nov. 5 2000

#include <ansi.h>
inherit ROOM;

int do_quit();
void create()
{
	set("short", "典当行");
	set("long", @LONG
这是一家刻薄出名的典当行。一进门正中就是一幅泼墨中堂，“典
当”二字淋漓而下，出入此处的人客都气为之夺。高高的柜台上面开了
一个小窗口，仅容物品递送和当银交接之用。抬眼望进去，柜台上摆着
一个牌子 (paizi)，柜台后面却是一个清清爽爽的女孩儿。你顿时全身
血液上冲：“东西当多少银两都值，只要能来多看她一眼”。
LONG
	);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
//	set("no_clean_up", 0);
	set("item_desc", ([
		"paizi" : "
pawn        当 
redeem      赎
value       估价

下面有两个墨迹未干的草体字    "HIR"停当\n"NOR,
	]));
	set("objects", ([
//		__DIR__"npc/ake" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"caohebeijie",
	]));

	set("coor/x", -10);
	set("coor/y", 31);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
