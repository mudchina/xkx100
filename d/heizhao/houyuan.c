// Room: /heizhao/houyuan.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "后院");
	set("long", @LONG
后院正中供奉着弥勒欢喜佛，佛像背面挺立着一个威猛的手持
长杵的护法韦陀。房内蒲团上居中坐着一个老僧，银须垂胸，厚厚
的僧衣直裹到面颊，正自低眉入定。有几名老和尚、小沙弥侍立两
旁。
LONG );
	set("no_clean_up", 0);
	set("objects", ([
		__DIR__"npc/xiaoshami2" : 2,
		__DIR__"npc/laoheshang" : 1,
		CLASS_D("dali")+"/yideng/yideng" : 1,
	]));
	set("exits", ([
		"south"  : __DIR__"zhulin1",
	]));
	set("coor/x", -5020);
	set("coor/y", -1000);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}