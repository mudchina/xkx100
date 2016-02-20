// Room: /yangzhou/lianxingsi.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "莲性寺");
	set("long", @LONG
莲性寺旧名“法海寺”，始建于隋唐，重建于元代至元年间。康熙
帝南巡时赐名“莲性寺”。山门面向东北，五楹，居中三间为天王殿，
内设佛龛，前坐弥勒，后立韦陀，两厢列四天王。两次间为楼房，后檐
上设方窗，下置板门。山门外两翼筑八字墙。
LONG );
	set("exits", ([
		"northeast" : __DIR__"pingtai4",
		"northwest" : __DIR__"shuixie",
		"southeast" : __DIR__"ouxiangqiao",
		"north"     : __DIR__"yunshange",
		"south"     : __DIR__"baitataji",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}