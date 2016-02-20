// Room: /d/yanziwu/path17.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "黄泥小路");
	set("long", @LONG
这是条黄泥小路，路边植着一列鲜嫩的青草，路东南是莲韵塘，路
北隔着柳丛，可以看到烟波太湖上的渔帆。白色渔帆下，赤脚渔子撒网
捕鱼，渔歌飘来，动听入耳。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest" : __DIR__"ouxiang1",
		"east"      : __DIR__"path16",
	]));
	set("coor/x", 1210);
	set("coor/y", -1220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}