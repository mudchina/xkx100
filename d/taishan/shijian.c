// Room: /d/taishan/shijian.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "试剑石");
	set("long", @LONG
经刻西北有巨石，高约两丈，宽近五丈，石辟为两半，上题“试剑
石”三字，又名仙峡石。万恭于明隆庆年间依崖筑石亭，柱联：“天门
倒泻一帘雨，梵石灵呵千载文。”崖摩刻《高山流水亭记》。万历年间
崔应麒摩刻草书《晒经石水帘诗》：“晒经石上水帘泉，谁挽银河落半
天。新月控钩朝挂玉，长风吹浪暮疑烟。梵音溅沫干还湿，曲涧流云断
复连。选胜具觞恣幽赏，题诗愧乏笔如椽。”
LONG );
	set("exits", ([
		"southeast" : __DIR__"jingshi",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 610);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
