// Room: /d/fuzhou/yangqiaoxiang.c
// Last Modifyed by Evil on Sep. 10 2002

inherit ROOM;

void create()
{
	set("short", "杨桥巷");
	set("long", @LONG
古名登俊坊，因西通杨桥而改名。附近有座双抛桥, 传说古时有一
对青年男女相爱, 不得如愿，双双投河殉情, 故名“双抛”。
LONG );

	set("exits", ([
		"west"    : __DIR__"nanhoujie1",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1837);
	set("coor/y", -6310);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
