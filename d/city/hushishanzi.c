// Room: /city/hushishanzi.c
// Last Modified by Winder on Jul. 15 2000

inherit ROOM;

void create()
{
	set("short", "湖石山子");
	set("long", @LONG
湖石山子横亘于院落当中，上与楼连，下与厅接。山上有石蹬盘旋，
山腹有洞弯曲迂回。更有两株白皮松植于山半，枝干虬曲，有凌空欲去
的气概，石蹬蜿蜒三折，有楼屋五楹，楼南临水而立。
LONG );
	set("exits", ([
		"west"       : __DIR__"shufengguan",
		"southwest"  : __DIR__"meichuanxuan",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", -47);
	set("coor/z", 0);
	set("no_quest",1);
	setup();
	replace_program(ROOM);
}