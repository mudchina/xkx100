// bobing2.c 东搏饼屋
// Last Modified by winder on Sep. 22 2002

#include <room.h>
#include <ansi.h>
//inherit ROOM;
inherit __DIR__"bobing.c";

void create()
{
	set("roomname","东间搏饼屋");
	set("no_fight","1");
	set("no_magic","1");
	set("no_steal","1");
	set("no_beg","1");
	set("short","东搏饼屋");
	set("long", @LONG
这是一间古朴典雅的的搏饼屋。房间的装修充满了盛明时候的风味，
满屋子的琳琅玉石衬着柔和的光线，洋溢着温馨的气氛，真是个温暖而
热闹的地方。房间的四周点着一溜松明子，中间一张楠木桌，大家都席
地而坐 (sit)，看着桌面上一个大海碗，碗里面滴溜溜转着六颗玉制的
骰子！南边的墙上贴着一张发黄的陈纸(paper)。
LONG);
	set("item_desc", ([
		"paper" : "介绍和命令请 help bobing。\n",
	]));
	set("objects",([
		__DIR__"npc/dog":1,
	]));
	set("exits", ([
		"west" : __DIR__"bobingting",
	]));
	set("no_clean_up",1);
	set("coor/x", 19);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
}