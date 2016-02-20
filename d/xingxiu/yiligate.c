// Room: /d/xingxiu/yili1.c
// Last Modified by winder on Apr. 25 2001
#include <ansi.h>
inherit ROOM;
void quarter_pass();

void create()
{
	set("short", "伊犁城南门");
	set("long", @LONG
伊犁，又名惠远，西通波斯，南到天竺，东与阳关、玉门相连，扼
中西交通的要冲，是丝绸之路上重要的旅站之一。伊犁城墙在伊犁河北
岸度地而筑，城高一丈四，地势险要。城墙上满布着炮台、枪眼，戒备
森严。
LONG
	);
	set("outdoors", "xiyu");
	set("exits", ([
		"south" : __DIR__"yilihe",
		"north" : __DIR__"yili",
	]));

	set("objects", ([
		__DIR__"npc/bing" : 2,
		__DIR__"npc/wujiang" : 2,
		__DIR__"npc/trader" : 1,
	]));
	set("coor/x", -39000);
	set("coor/y", 12000);
	set("coor/z", 0);
	setup();
//	quarter_pass();
}
/*
void quarter_pass()
{
	mixed *local;

	local = localtime(time() * 60);
	if (local[2] < 6 || local[2] >= 21)
	{
		set("long", @LONG
伊犁，又名惠远，西通波斯，南到天竺，东与阳关、玉门相连，扼
中西交通的要冲，是丝绸之路上重要的旅站之一。伊犁城墙在伊犁河北
岸度地而筑，城高一丈四，地势险要。城墙上满布着炮台、枪眼，戒备
森严。现在是夜间，城门已关，只有几个回族士兵在城门口守夜。
LONG);
		delete("exits/north");
	}
	else {
		set("long", @LONG
伊犁，又名惠远，西通波斯，南到天竺，东与阳关、玉门相连，扼
中西交通的要冲，是丝绸之路上重要的旅站之一。伊犁城墙在伊犁河北
岸度地而筑，城高一丈四，地势险要。城墙上满布着炮台、枪眼，戒备
森严。
LONG);
		set("exits/north", __DIR__"yili2");
	}
	call_out("quarter_pass", 30);
}
*/
