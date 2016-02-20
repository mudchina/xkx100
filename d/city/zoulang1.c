// Room: /city/zoulang1.c
// Last modified by winder 2002.11.11

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "走廊");
	set("long", @LONG
这是赌场里的走廊，来来往往的小二和骂骂咧咧赌徒，夹杂着满空
气里弥散的烟酒汗气，实在是繁杂。各个方向的房间里，牌九、骰子和
麻将巧击声，桌椅板凳推倒敲砸声，酒杯器皿的落地破碎声，交杂成让
让人极其兴奋的气氛。你一走进这里，不禁叹道，真是好地方。
LONG);
	set("exits", ([
		"east"   : __DIR__"zoulang2",
		"north"  : __DIR__"paixiting",
		"south"  : __DIR__"majiangting",
		"west"   : __DIR__"duchang",
	]));
        set("no_fight","1");
	set("no_clean_up", 0);
	set("outdoors", "duchang");
	set("coor/x", 21);
	set("coor/y", 0);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
void init()
{
	object me = this_player();
	if (me->query("gender") != "男性")
		set("long", @LONG
这是赌场里的走廊，来来往往的小二和骂骂咧咧赌徒，夹杂着满空
气里弥散的烟酒汗气，实在是繁杂。各个方向的房间里，牌九、骰子和
麻将巧击声，桌椅板凳推倒敲砸声，酒杯器皿的落地破碎声，交杂成让
让人极其兴奋的气氛。你一走进这里，就皱起眉头：什么鬼地方。
LONG);
	return;
}
