// Room: /d/taishan/guanriting.c
// Last Modified by Winder on Aug. 25 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "观日亭");
	set("long", @LONG
玉皇庙东厢就是观日亭。旭日东升是泰山最迷人的奇观。拂晓，天
晴气朗，万壑收暝，东方一线晨曦由灰暗变淡黄，又由淡黄变成橘红。
继而，天空云朵赤紫交杂，瞬息万变。满天彩霞与地平线上的茫茫雾气
连为一体，云霞雾霭相映。赤轮乍启，海面半吞半吐，欲上而止，跳荡
恍惚，仿佛有二日捧出。待日轮掀开云幕，冉冉升起，宛若飘荡着的宫
灯。顷刻间，金光四射，群峰尽染。
LONG );
	set("exits", ([
		"west" : __DIR__"yuhuang",
	]));
	set("objects", ([
		"/d/village/npc/seller" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 370);
	set("coor/y", 780);
	set("coor/z", 210);
	setup();
	replace_program(ROOM);
}
