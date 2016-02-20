// Room: /d/taishan/baidong.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "柏洞");
	set("long", @LONG
你走到这里，但见古柏夹道，浓郁遮天，人行其中如入洞穴，虽炎
夏酷暑而凉气宜人，暑气顿消。清代张玢题“柏洞”。
LONG );
	set("exits", ([
		"northup" : __DIR__"sihuaishu",
		"south"   : __DIR__"dengxian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 630);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
