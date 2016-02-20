// Room: /d/nanyang/dajie1.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;
void create()
{
	set("short", "南大街");
	set("long", @LONG
南阳城自古便是关、洛通荆、襄的必经之路。城虽不大，却很是整
洁，且民风淳朴。大街上人喊马嘶，尽是南来北往的行商。街西边是一
家商号。
LONG);
	set("exits",([
		"north" : __DIR__"nanyang",
		"south" : __DIR__"nanmen",
		"west"  : __DIR__"shop",
	]));
	set("objects",([
		"/d/taishan/npc/tiao-fu" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", 490);
	set("coor/z", 0);
	set("outdoors","nanyang");
	setup();
	replace_program(ROOM);
}
