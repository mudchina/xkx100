// Room: /d/fuzhou/taxiang.c
// Last Modifyed by Evil on Sep. 10 2002

inherit ROOM;

void create()
{
	set("short", "塔巷");
	set("long", @LONG
原名修文巷，宋代改称兴文巷、文兴巷。以闽国时建育王塔于巷北
而改今名。塔系木构，后不知毁于何时。清代在巷内砌造半爿小塔，作
为古迹纪念。
LONG );

	set("exits", ([
		"west"    : __DIR__"nanhoujie3",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1837);
	set("coor/y", -6330);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
