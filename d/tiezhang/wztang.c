// Room: /d/tiezhang/wztang.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;
string look_bian();

void create()
{
	set("short", HIY"五指堂"NOR);
	set("long", @LONG
这是一间完全用花岗岩砌成的大厅，透出阵阵逼人的寒气。整座房
屋没有窗户，显得阴森黑暗。两旁的墙壁上插着松油火把，散发出昏黄
的光亮，寂静的大厅中不时响起火把噼啪的燃烧声。大厅的正中摆放着
帮主的宝座，两旁分列着十几把椅子，只有遇到帮中大事时，帮主才会
在这里与部下商议。在正面的墙上挂着一面缕金的横匾(bian)。北面有
一扇小门通向后面。
LONG	);
	set("item_desc", ([ 
		"bian" : (: look_bian :),
	]));
	set("exits", ([ 
		"east"      : __DIR__"zoulang1",
		"west"      : __DIR__"zoulang2",
		"north"     : __DIR__"hxfang",
		"southdown" : __DIR__"guangchang",
	]));
	set("objects", ([ 
		CLASS_D("tiezhang")+"/qqren" : 1,
		__DIR__"npc/xiaotong" : 1,
	]));
	set("no_clean_up", 0);
	set("coor/x", -2040);
	set("coor/y", -1960);
	set("coor/z", 30);
	setup();
	
}
string look_bian()
{
	return
	"\n"HIY
	"          ####################################\n"
	"          ####                            ####\n"
	"          ####    五    指    擎    天    ####\n"  
	"          ####                            ####\n"
	"          ####################################\n"NOR;
	"\n";
}