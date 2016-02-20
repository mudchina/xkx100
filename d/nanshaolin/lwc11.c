// Room: /d/nanshaolin/lwc11.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是少林寺的练武场。由无数块巨大的花岗岩石板铺就。上千年
的踩踏已使得这些石板如同镜子般平整光滑。十来个僧人正在练习武技。
南北西三面各有一练武场。
LONG );
	set("exits", ([
		"north" : __DIR__"lwc12",
		"east"  : __DIR__"banruo5",
		"west"  : __DIR__"lwc15",
		"south" : __DIR__"lwc19",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1870);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

