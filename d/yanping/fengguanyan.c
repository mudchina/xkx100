// Room: /d/yanping/fengguanyan.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "凤冠岩");
	set("long", @LONG
凤冠岩伫立在建溪之畔，如刃立起，下临深水。岩上悬空支起一座
禅林，号明翠阁。日日晨钟暮鼓，全城皆沐佛号，檀香佛唱，斯民尽惠
春霖。凭阁下瞰，溪水流碧，百筏争游。真可谓“不出城廓而获山水之
怡，身居闹市而有林泉之致”。
    对岸便是马站，有官道前往福州。
LONG );
	set("exits", ([
		"up"        : __DIR__"mingcuige",
		"south"     : __DIR__"dongmen",
		"northwest" : __DIR__"yidao3",
	]));
	set("outdoors", "yanping");
	set("no_clean_up", 0);
	set("coor/x", 1520);
	set("coor/y", -6160);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
