// Room: /heizhao/chanyuan.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "禅院");
	set("long", @LONG
你步入殿内，只见大殿上佛前供着一盏油灯，映照着佛像宝相
庄严。一个小沙弥正跪倒在蒲团上暗暗祷祝。左右两壁立着四大天
王塑像，举剑执蛇，神情甚是灵动。
LONG );
	set("no_clean_up", 0);
	set("valid_startroom", 1);
	set("objects", ([
		__DIR__"npc/xiaoshami" : 1,
	]));
	set("exits", ([
		"east"       : __DIR__"dongxiang",
		"west"       : __DIR__"xixiang",
		"southdown"  : __DIR__"shiqiao",
		"north"      : __DIR__"houxiang",
	]));
	set("coor/x", -5020);
	set("coor/y", -1200);
	set("coor/z", 50);
	setup();
	"/clone/board/yideng_b"->foo();
}