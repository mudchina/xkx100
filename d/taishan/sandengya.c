// Room: /d/taishan/sandengya.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "三蹬崖");
	set("long", @LONG
沿阶而上，来到三蹬崖，上有巨石如屋，明万历年间，盛夏遇暴风
雨，石自山巅坠此，柯绍皋题“飞来石”。御帐坪东有望驾石，如老翁
拱立。
LONG );
	set("exits", ([
		"eastdown"   : __DIR__"yunbu",
		"westup"     : __DIR__"wudafu",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 380);
	set("coor/y", 680);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}
