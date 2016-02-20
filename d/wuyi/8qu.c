// Room: /d/wuyi/8qu.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "八曲");
	set("long", @LONG
八曲崖岸的骆驼峰，是由三块巨大的岩峰排列而成。小头，耸立
的驼峰，宽大的驼背，真是感叹天工的造化。朱熹《九曲棹歌》曰：
“……八曲风烟势欲开，鼓楼岩下水潆洄。莫言此地无佳景，自是游
人不上来。……”
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"southup"   : __DIR__"mopanshi",
		"northwest" : __DIR__"pinziyan",
		"northeast" : __DIR__"7qu",
		"southwest" : __DIR__"9qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1330);
	set("coor/y", -5020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

