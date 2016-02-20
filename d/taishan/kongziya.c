// Room: /d/taishan/kongziya.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "孔子崖");
	set("long", @LONG
孔子崖位于天街东首路北山岗上。传孔子与颜子登泰山至此，孔子
东南望，看见 吴国都城门下的一匹白马，此处遂名孔子崖或称望吴峰。
崖上有“泰山乔岳”、“高山仰止”诸刻。
LONG );
	set("exits", ([
		"northdown" : __DIR__"kongzimiao",
		"southdown" : __DIR__"tianjie",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 370);
	set("coor/y", 780);
	set("coor/z", 220);
	setup();
	replace_program(ROOM);
}
