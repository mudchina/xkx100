// Room: /d/yanziwu/mingzhu.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "明珠楼");
	set("long", @LONG
这里是蔓陀山庄的主楼上房。楼建得非常富丽堂皇，飞檐琉瓦，画
栋雕廊，还有一只尺高的鹦鹉挂在栏下。楼名“明珠”，取自诗句“还
君明珠泪双垂，恨不相逢未嫁时”。寄托着主人过去的一番情孽。不过
时间已经过去很久了，大家都不知道这个事情了知道的人也不敢在主人
面前提起了。
LONG );
	set("exits", ([
		"south"  : __DIR__"path11",
	]));
	set("objects", ([
		__DIR__"npc/wangfuren" : 1,
	]));
	set("coor/x", 1240);
	set("coor/y", -1210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}