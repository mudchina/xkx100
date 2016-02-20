// Room: /d/wuyi/mopanshi.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "磨盘石");
	set("long", @LONG
磨盘石在八曲之南。两块椭圆而挺拔的巨石叠合在一起，状如一副
磨盘。经雨水冲刷而形成的一束束乳白的浆液从磨盘的中央裂缝中汨汨
往下流淌，真切而动感。宋朝李纲诗曰：“仙家何事也储粮，石廪团团
曲水傍。应驾玉龙耕紫石，琼芝千亩个中藏。”
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"8qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1330);
	set("coor/y", -5030);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

