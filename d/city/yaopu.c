// Room: /city/yaopu.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "药铺");
	set("long", @LONG
这是一家药铺，一股浓浓的药味让你几欲窒息，那是从药柜上的几
百个小抽屉里散发出来的。神医平一指坐在茶几旁，独自喝着茶，看也
不看你一眼。一名小伙计站在柜台后招呼着顾客。柜台上贴着一张发黄
的广告(guanggao)。
LONG );
	set("item_desc", ([
		"guanggao" : "本店出售以下药品：
金创药：\t五十两白银
无常丹由桃花岛黄药师所配，生死肉骨．
朱睛冰蟾救治百毒，无效包换．
其他神药与老板面议。\n",
	]));
//	set("item_desc", ([
//		"guanggao" : "本店老板平一指外出采药未归，今日暂停营业。\n",
//	]));
	set("objects", ([
//		__DIR__"npc/ping" : 1,
		"/kungfu/class/heimuya/ping" : 1,
		__DIR__"npc/huoji" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"shilijie6",
		"east" : __DIR__"yaopu2",
	]));
//	set("no_clean_up", 0);
	set("coor/x", 15);
	set("coor/y", -30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
