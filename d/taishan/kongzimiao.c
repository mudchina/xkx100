// Room: /d/taishan/kongzimiao.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "孔子庙");
	set("long", @LONG
孔子庙位于孔子崖下，明嘉靖年间尚书朱衡建。庙有山门、正殿、
配殿，内奉孔子，配祀颜子、曾子、子思、孟子等。山门上有清人徐宗
干题联：“仰之弥高，钻之弥坚，可以语上也；出乎其类，拔乎其萃，
宜若登天然。”
LONG );
	set("exits", ([
		"southup" : __DIR__"kongziya",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 370);
	set("coor/y", 790);
	set("coor/z", 210);
	setup();
	replace_program(ROOM);
}
