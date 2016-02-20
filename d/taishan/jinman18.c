// Room: /d/taishan/man18.c
// Last Modified by winder on Aug. 25 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "紧慢十八盘");
	set("long", @LONG
你走在不紧不慢十八盘上，两腿发软，挥汗如雨。两边是光秃的岩
壁，无处可以遮风避日。十八盘的两山崖壁如削，陡峭的盘路镶嵌其中，
远远望去，恰似天门云梯。回头看看，人行如蚁，尽在脚下。上头离南
天门还好远呢。泰山之雄伟，尽在十八盘；泰山之壮美，尽在攀登中！ 
LONG );
	set("exits", ([
		"northup"   : __DIR__"shengxian",
		"southdown" : __DIR__"longmen",
	]));
	set("objects", ([
		__DIR__"npc/tiao-fu" : 1,
	]));
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 740);
	set("coor/z", 170);
	setup();
	replace_program(ROOM);
}
