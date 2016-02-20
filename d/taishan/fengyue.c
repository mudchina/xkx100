// Room: /d/taishan/fengyue.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "风月无边");
	set("long", @LONG
斗母宫南西崖有“蔚然深秀”、“洞天福地”、“肤寸升云”及“
虫二”诸刻，与山色辉映。“虫二”字谜即“风月”二字拆去边框，意
为风月无边，景色秀丽。
LONG );
	set("exits", ([
		"northeast" : __DIR__"doumo",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 390);
	set("coor/y", 590);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
