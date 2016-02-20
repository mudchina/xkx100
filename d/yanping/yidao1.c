// Room: /d/yanping/yidao1.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "闽浙驿道");
	set("long", @LONG
自古入闽无敞途。往来货运全靠肩挑背扛，逶迤入闽，车马不通。
古驿道沿建溪溪流南下，山岩交叠，茅草相簇，飞蠓毛虫一路陪同，艰
苦万状。好在山该青处皆清，碧水清澈爽口，巨树修竹插天，虽然一路
而来，口音渐变，倒也另有一番情趣。
LONG );
	set("exits", ([
		"northdown" : __DIR__"shandao1",
		"southup"   : __DIR__"yidao2",
	]));
	set("objects", ([
		"/d/taishan/npc/tiao-fu" : 2,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1500);
	set("coor/y", -6000);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
