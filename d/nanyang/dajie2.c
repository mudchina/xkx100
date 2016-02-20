// Room: /d/nanyang/dajie2.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;
void create()
{
	set("short", "北大街");
	set("long", @LONG
南阳城自古便是关、洛通荆、襄的必经之路。城虽不大，却很是整
洁，且民风淳朴。街西有一家小小的店铺，卖些酒水，肉食给过往的行
人。东北面是一个大庙。
LONG);
	set("exits",([
		"north"     : __DIR__"beimen",
		"south"     : __DIR__"nanyang",
//		"west"      : __DIR__"xiaodian",
		"northeast" : __DIR__"wuhouci",
	]));
	set("objects",([
		__DIR__"npc/man":1,
	]));
	set("outdoors","nanyang");
	set("coor/x", 10);
	set("coor/y", 510);
	set("coor/z", 0);
	setup();
	set("no_clean_up", 0);
}
