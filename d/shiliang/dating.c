// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
	set("short", "大厅");
	set("long", @LONG
你来到温家大宅会客的大厅里，这里灯火通明，屋内陈设很
是精巧，两个制作精美的有一人般高的大瓷瓶放在厅的两侧，四
周的墙上挂着许多文人墨客的字画，大厅上面有块匾，上书“正
义堂”三个大字。有个中年人正坐在八仙桌旁悠闲地喝着茶，好
象在沉思着什么。
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"yuanzi",
		"northwest" : __DIR__"zoulang1",
		"northeast" : __DIR__"zoulang5",
	]));
	set("objects", ([
		__DIR__"npc/wenfangda" : 1,
		__DIR__"npc/yahuan" : 2,
	]));
	set("coor/x", 1610);
	set("coor/y", -1950);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}