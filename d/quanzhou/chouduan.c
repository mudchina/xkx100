// Room: /d/quanzhou/chouduan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "鸿翔绸缎庄");
	set("long", @LONG
这就是天下闻名的丝绸销售中心，古色古香的店面，门上挂干飘着
一面质地上好的绸面，绣着红色的「鸿翔绸缎」四个大字。中原来的上
等丝绸在此加工后源源不断的运往西洋各国。庄内各式花色和质地的绸
缎应有尽有，琳琅满目。
LONG );
	set("exits", ([
		"west"   : __DIR__"road1",
	]));
	set("objects", ([
		__DIR__"npc/xu" : 1,
	]));
	set("coor/x", 1870);
	set("coor/y", -6590);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
