// Room: /yangzhou/pingtai1.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "平台");
	set("long", @LONG
由风亭西行下山，石径中段有一平台，平台石栏为法海寺遗物。在
此远眺五亭桥、白塔、钓鱼台诸景最佳。出平台，过山涧石梁，即达观
音殿。
LONG );
	set("outdoors", "shouxihu");
	set("exits", ([
		"westdown" : __DIR__"guanyindian",
		"eastup"   : __DIR__"fengting",
	]));
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 120);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}