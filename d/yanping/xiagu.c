// Room: /d/yanping/xiagu.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "溪源峡谷");
	set("long", @LONG
溪源峡谷“原始风物天然美，神瀑幽谷甲东南”。此地之水，变化
多端。有猛浪若奔的激濑，也有汨汨而淌的细流；有腾空飞写的瀑布，
也有随风飘洒的水帘；有沿崖淌落的岩流，也有潜入于岩的冷泉。十里
溪山，山光水色，上下交映，犹如一幅天然水墨长卷。
LONG );
	set("exits", ([
		"northup"   : __DIR__"xiyuanan",
		"southeast" : __DIR__"youlang",
	]));
	set("outdoors", "yanping");
	set("no_clean_up", 0);
	set("coor/x", 1420);
	set("coor/y", -6130);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
