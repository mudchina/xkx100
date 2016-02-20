// Room: /d/yanziwu/path23.c
// Date: Jan.28 2000 by Winder

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "青草路");
	set("long", @LONG
沿着青草路，慢慢爬上蔓陀山峰。脚下踩着软软的小草，满目的清
亮透绿，鼻子里闻着青青的春泥香味，你想：哦，这就是江南。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"northup"   : __DIR__"path24",
		"southdown" : __DIR__"path22",
	]));
	set("coor/x", 1210);
	set("coor/y", -1260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}