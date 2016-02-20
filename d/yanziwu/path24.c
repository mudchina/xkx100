// Room: /d/yanziwu/path24.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "青草路");
	set("long", @LONG
沿着青草路，慢慢爬上蔓陀山峰。渐行渐高，慢慢的，山脊落在了
下面，波涛潋滟的太湖慢慢占据了你的视野。青天白云，远山飞雁，好
象越来越近了。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown" : __DIR__"path23",
		"northup"   : __DIR__"luanyun",
		"east"      : __DIR__"tianfeng",
	]));
	set("coor/x", 1210);
	set("coor/y", -1250);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}