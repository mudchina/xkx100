// Room: /d/yanziwu/path16.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "黄泥小路");
	set("long", @LONG
这是条黄泥小路，路边植着一列鲜嫩的青草，路南是莲韵塘，路北
隔着柳丛，可以看到烟波太湖上的渔帆。白色渔帆下，赤脚渔子撒网捕
鱼，渔歌飘来，动听入耳。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"bridge3",
		"west"  : __DIR__"path17",
		"east"  : __DIR__"bridge2",
	]));
	set("coor/x", 1220);
	set("coor/y", -1220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}