// Room: /heizhao/shiqiao.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "小石桥");
	set("long", @LONG
这是一座青石铺砌的小石桥，长虹卧波般连通荷塘两岸。站在
桥上俯视，荷塘水面随风皱眉。偶有几只青蛙从田田莲叶上钻入水
底，带动着一阵阵涟漪。南面望去，荷塘外群山下伏，层雾缭绕，
云远天清。
LONG );
	set("outdoors", "taoyuan");
	set("no_clean_up", 0);
	set("exits", ([
		"south"   : __DIR__"hetang",
		"northup" : __DIR__"chanyuan",
	]));
	set("coor/x", -5020);
	set("coor/y", -1210);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}