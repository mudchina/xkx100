// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "书房");
	set("long", @LONG
温家的书房很大，墙边摆满了一书架一书架的书，一张书桌上
放着文房四宝，檀香正燃着，屋内充满了那种神秘的香气，其实温
氏五老都是草莽出身，平时难得到这里一次。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ 
		"west" : __DIR__"zoulang7",
	]));
	set("coor/x", 1630);
	set("coor/y", -1920);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}