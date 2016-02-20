// Room: /d/wuyi/xiangshengyan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "响声岩");
	set("long", @LONG
位于六曲溪南的响声岩，又名下城高。因有空谷传声的感应，故名
响声岩。朱熹手迹“逝者如斯”四字于此，为武夷山最早的摩崖石刻。
隔溪斜对面，就是云窝了。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"northdown" : __DIR__"6qu",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1350);
	set("coor/y", -5020);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

