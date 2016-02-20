// Room: /yangzhou/xichuntai.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","熙春台");
	set("long",@LONG
熙春台面东三楹，二层重檐，前加抱厦，七架梁，歇山，上覆铬绿
琉璃瓦，脊饰龙藻图案，飞甍反宇。四面廊，楼层四周围以槛窗，以便
远眺二十四桥和湖山胜景。底层，上悬康殷手书“春台祝寿”匾额，两
柱悬挂江湘岚楹联(lian)。迎面有巨幅“玉女月夜吹箫图”，为扬州漆
画工艺品。漆画前设置漆器琴桌和圆凳，可演奏古筝。
LONG );
	set("item_desc", ([
		"lian" : HIM"
胜地据淮南，看云影当空，与水平分秋一色
扁舟过桥下，闻箫声何处，有人吹到月三更
\n"NOR,
	]));
	set("exits", ([
		"eastdown" : __DIR__"pingtai5",
		"up"       : __DIR__"xichuntai1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -60);
	set("coor/y", 100);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}