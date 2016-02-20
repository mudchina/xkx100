// Room: /yangzhou/yueguan.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "月观");
	set("long", @LONG
月观坐西朝东，前临湖滨，后濒桂园，月光之下，粼粼水波，连成
一璧，实乃扬州赏月胜地。堂中悬挂着陈重庆题书“月观”横匾，堂前
挂一抱柱楹联(lian)，为“扬州八怪”之一的郑坂桥所书。四壁悬挂四
片大型清代大理石挂屏，以海梅为框，樱木为膛，每片各嵌有方圆二幅
天然山水纹饰大理石，并有题款，至为珍贵。面东护以木槛，槛外疏柳
三五株横卧水际。
LONG );
	set("exits", ([
		"west"     : __DIR__"qishi",
		"northup"  : __DIR__"fengting",
	]));
	set("item_desc", ([
		"lian" : HIC"
        月        云
        来        起
        满        一
        地        天
        水        山
\n"NOR,
	]));
	set("no_clean_up", 0);
	set("coor/x", 30);
	set("coor/y", 110);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}