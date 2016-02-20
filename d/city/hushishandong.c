// Room: /city/hushishandong.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "湖石山洞");
	set("long", @LONG
洞在湖石山子中腹，窍穴甚多，一面可以疏通天光，一面可以看见
树摇清影。人在山腹，而无一丝窒息之感。北端临池曲，有水清碧。各
色品种的金鱼，群嬉于池底。水上架石梁三曲。
LONG );
	set("exits", ([
		"north"  : __DIR__"luqiao",
		"south"  : __DIR__"tianjing",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("coor/x", -22);
	set("coor/y", 2);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}