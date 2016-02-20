// Room: /d/wuyi/pinziyan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "品字岩");
	set("long", @LONG
品字岩在八曲之北。自古武夷山就是三教同山的典范。儒、释、道
互不排斥，包容并蓄，三花并蒂，堪称奇迹。因此，此峰也叫三教峰。
由于角度不同，此峰又甚似文人笔架，故又名笔架峰。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"8qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1320);
	set("coor/y", -5010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

