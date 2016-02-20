//Edited by fandog, 01/31/2000
#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", HIR"赤壁"NOR);
	set ("long", @LONG
这是伸展在大江之中的一座小石山。临江的峭壁上刻有“赤壁”两
个大字，相传是三国时期周瑜所书。三国时孙权与刘备合兵，在这里用
火攻大破曹操的八十万大军，把曹军的水兵、军船一燃而尽。当时江面
烈火熊熊，把大江南岸的石壁照得通红，从此，人们就将江边这座小石
山为“赤壁”。
LONG);
	set("outdoors", "jiangling");
	set("exits", ([ 
		"south" : __DIR__"huanghelou",
		"north" : __DIR__"matou2",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1400);
	set("coor/y", -2210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
