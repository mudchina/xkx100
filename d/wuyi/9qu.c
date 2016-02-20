// Room: /d/wuyi/9qu.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "九曲");
	set("long", @LONG
九曲在两峰夹缝中流淌，西面往去，就是一马平川了。溪流在此
慢慢闪动，全长二十里的九曲溪由此东去，穿越丛峰，直抵崇阳溪。
朱熹《九曲棹歌》曰：“……九曲将穷眼豁然，桑麻雨露见平川。渔
郎更觅桃源路，除是人间别有天。”
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northeast" : __DIR__"8qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1320);
	set("coor/y", -5030);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

