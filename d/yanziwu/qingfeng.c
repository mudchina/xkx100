// Room: /d/yanziwu/qingfeng.c
// Date: Jan.28 2000 by Winder
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "青风坪");
	set("long", @LONG
这里是藕香小筑前的草坪。草坪半掩在山谷中，形同半月上弦，南
面小山缺口过去，是通去秋雨斋的小路。北面沿着水边小路转过半个山
坳去，就是藕香小筑了。
LONG );
	set("outdoors", "mantuo");
	set("exits", ([
		"northwest"  : __DIR__"path18",
		"southup"    : __DIR__"path19",
	]));
	set("objects", ([
	]));
	set("coor/x", 1200);
	set("coor/y", -1250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}