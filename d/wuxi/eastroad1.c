// Room: /d/wuxi/eastroad1.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "东林路");
	set("long", @LONG
宽阔的青石板街道打扫得干干净净，西边就是城中心的三阳广场了，
人声鼎沸，十分热闹。相比起来这里就显得冷清了许多，这是因为北面
正是无锡的知府衙门，漆红的官门八字敞开，一面大红鼓正对路中心，
一股威严之气让人不由地放轻声音，加快脚步。南边是驻军练兵的练兵
场，一直通向军营。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"yamen",
		"south" : __DIR__"zhengbing",
		"east"  : __DIR__"eastroad2",
		"west"  : __DIR__"guangchang",
	]));
	set("coor/x", 380);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}