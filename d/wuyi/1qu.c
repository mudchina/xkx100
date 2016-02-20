// Room: /d/wuyi/1qu.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "一曲");
	set("long", @LONG
“曲曲山回转，峰峰水抱流”。这里就是天下驰名的武夷山九曲溪
了。溪岸北边是道教圣地武夷宫。南岸是大小观音岩。溪水到这里流速
平缓，东去汇如崇阳溪。朱熹《九曲棹歌》曰：“武夷山上有仙灵，山
下寒流曲曲清。欲识个中奇绝处，棹歌闲听两三声。一曲溪边上钓船，
幔亭峰影蘸晴川。虹桥一断无消息，万壑千岩锁翠烟。……”
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"2qu",
		"north"     : __DIR__"wuyigong",
		"northwest" : __DIR__"path1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1400);
	set("coor/y", -5010);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

