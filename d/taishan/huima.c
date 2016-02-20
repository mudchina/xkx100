// Room: /d/taishan/huima.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "回马岭");
	set("long", @LONG
回马岭古名石关，又名天关、瑞仙岩。此地山势陡峭，峰回路转，
马至此不能登，故名。据说当年唐玄宗上泰山封禅，来到这里，因陡峭
难攀，累死了白马，要改乘小轿上山。石坊后盘路岌岌陡绝，东南上而
西北折，形似马蹄，故称马蹄盘。崖壁题“勒马回看岱岭云”。
LONG );
	set("exits", ([
		"northup"  : __DIR__"ertian",
		"eastdown" : __DIR__"hutiange",
	]));
	set("objects",([
		__DIR__"npc/tiao-fu" : 1,
		__DIR__"npc/jian-ke" : 1,
	]));
//	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 390);
	set("coor/y", 650);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
