// Room: /d/taishan/duisong.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "对松山");
	set("long", @LONG
出朝阳洞北去，便是对松山。对松山双峰对峙，古松万株，苍翠蓊
郁，层层叠叠，又名万松山、松海。云出其间，天风莽荡，虬舞龙吟，
松涛大作，堪称奇观。李白有“长松入云汉，远望不盈尺”的诗句。乾
隆则称“岱宗穷佳处，对松真绝奇”。
LONG );
	set("exits", ([
		"southdown" : __DIR__"chaoyang",
		"northup"   : __DIR__"kaishan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 700);
	set("coor/z", 130);
	setup();
	replace_program(ROOM);
}
