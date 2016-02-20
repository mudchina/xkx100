// /d/meizhuang/zoulang2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这是一条长长的走廊，走廊两边是四位庄主中的其他三位平时休息
和练功的地方，这里的左边是棋室，右边则是梅庄弟子感觉劳顿的时候
休息的地方，二庄主黑白子不分昼夜都在棋室里研究他那些不知道哪儿
找来的古棋谱。 
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"qishi",
		"east"  : __DIR__"xiuxishi",
		"north" : __DIR__"zoulang3",
		"south" : __DIR__"zoulang1",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3500);
	set("coor/y", -1370);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
