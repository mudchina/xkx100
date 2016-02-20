// Room: /d/taishan/taohua.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "桃花涧");
	set("long", @LONG
桃花涧，又名樱桃园，清人曾颂：“樱桃生涧底，石上多古苔。山
下花已落，山头花未开。”涧中石坪广阔，断崖跌宕，溪水潺潺而来，
滢洄湍急而去，或为瀑，或为潭，或潜流，汇为深广碧池，名碧泉湾。
今涧内桃、樱均无，唯杨、槐满谷，柏林夹岸，石峡飞流，瀑水如帘。
LONG );
	set("exits", ([
		"northup" : __DIR__"doumo",
		"south"   : __DIR__"wanxianlou",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 590);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
