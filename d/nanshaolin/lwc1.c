// Room: /d/nanshaolin/lwc.c
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
		"east"  : __DIR__"lhtang",
		"west"  : __DIR__"lwc5",
		"north" : __DIR__"lwc2",
		"south" : __DIR__"lwc9",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1790);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

