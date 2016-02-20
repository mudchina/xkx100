// Room: /d/wuxi/canhetang.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "参和堂");
	set("long", @LONG
参和堂是无锡城的老字号药铺了，浓浓的药味早已经深入店堂里的
每根椽柱之中，柜台后的几百个小抽屉上贴着各种中药的名称。药铺帐
房坐在茶几旁，独自喝着茶，翻看着手上的帐单。一名小伙计站在柜台
后招呼着顾客。柜台上贴着一张发黄的广告(guanggao)。
LONG );
	set("item_desc", ([
		"guanggao" : "本店出售以下药品：
金创药：\t五十两白银
无常丹由桃花岛黄药师所配，生死肉骨．
朱睛冰蟾救治百毒，无效包换．
其他神药与老板面议。\n",
	]));
	set("exits", ([
		"east" : __DIR__"northroad2",
	]));
	set("objects", ([
		"/d/city/npc/huoji" : 1,
	]));
	set("coor/x", 360);
	set("coor/y", -770);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}