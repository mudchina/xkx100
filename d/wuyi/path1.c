// Room: /d/wuyi/path1.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是两峰夹缝中的一条小路。路面是丹崖石板铺就的，两边都是高
耸的山峰。路边有条数尺宽的小沟，沟里终年流动着清澈的泉水，水中
时而闪现寸许长的游鱼。小路时宽时窄。窄时不过数尺，举手可抚山岩。
宽处也有数丈，路边便都是层叠的茶林。岩壁上流淌的泉水，滋润着一
片片葱绿的希望。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northup"   : __DIR__"dawangfeng",
		"southeast" : __DIR__"1qu",
	]));
	set("objects", ([
		"/d/huashan/npc/youke" : random(3),
	]));
	set("coor/x", 1390);
	set("coor/y", -5000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

