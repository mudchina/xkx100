// Room: /d/wuyi/jingtai.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "镜台");
	set("long", @LONG
这里紧靠二曲之南，黝黑的岩壁上大书“镜台”二字，便是九天上
仙女来此沐浴后梳妆的镜台了。镜台与玉女峰相对，远远望去，便如玉
女临镜插花的形态。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northwest" : __DIR__"yunvfeng",
		"south"     : __DIR__"huxiaoyan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1390);
	set("coor/y", -5020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

