// Room: /d/songshan/jianlu.c
// Last Modified by Winder on Jul. 15 2001

#include <ansi.h>
inherit ROOM;
int do_zong(string arg);

void create()
{
	set("short", "剑庐");
	set("long", @LONG
这是一间净室，室内一物不设。窗外偶尔光线斜入，映见正中梁顶
似乎存放着一些物事。
LONG );
	set("sword_count", 1);
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"eastting",
	]));
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 900);
	set("coor/z", 90);
	setup();
}
void init()
{
	add_action("do_zong", "zong");
	add_action("do_zong", "tiao");
	add_action("do_zong", "jump");
}
int do_zong(string arg)
{
	object ob, me= this_player();
	if (arg != "sword" && arg != "liang") return 0;
	if( (int)me->query_dex() < 38 )
		return notify_fail("你纵起身形，一掠而起，就差一点就可以够到梁了，真是可惜。\n");
	if (query("sword_count") < 1)
		return notify_fail("你纵起身形，一掠而起，伸手往梁上一摸，却不料摸了一个空。\n");
	add("sword_count", -1);
	ob = new(WEAPON_DIR"treasure/zhanlu-jian");
	if ( ob->violate_unique() )
	{
		destruct( ob );
		return notify_fail("你纵起身形，一掠而起，伸手往梁上一摸，却不料摸了一个空。\n");
	}
	ob->move(me);
	message_vision("$N纵起身形，一掠而起，伸手往梁上一摸，一个鹞子翻身轻轻落地，手上多了一把外形古朴的长剑。\n", me);
	return 1;
}
