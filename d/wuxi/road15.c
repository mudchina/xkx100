// Room: /d/wuxi/road15.c
// Winder 2000/02/22 

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "山路");
	set("long", @LONG
山路曲曲折折，四周花草成丛，林荫茂盛。仰身长啸，但听空山
鸟语。回音阵阵。山下天下第二泉早已没入一片密密的竹林之中，再
向山上就快要到惠山的顶峰了。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"northup"    : __DIR__"huishan",
		"southdown"  : __DIR__"huishanquan",
	]));
	set("coor/x", 260);
	set("coor/y", -170);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}