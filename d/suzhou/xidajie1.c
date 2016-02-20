// Room: /d/suzhou/xidajie1.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。西大街是衙门所在，
行人稀少，静悄悄地很是冷清。东边是沧浪亭和宝带桥，南边是兵营。
北边就是衙门了。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"xidajie2",
		"north"     : __DIR__"yamengate",
		"south"     : __DIR__"bingyinggate",
		"southeast" : __DIR__"baodaiqiao",
		"northeast" : __DIR__"canlangting",
		"northwest" : __DIR__"szyunhe",
	]));
	set("coor/x", 840);
	set("coor/y", -1010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
