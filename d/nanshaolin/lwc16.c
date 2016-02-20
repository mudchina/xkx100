// Room: /d/nanshaolin/lwc16.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是少林寺的练武场。由无数块巨大的花岗岩石板铺就。上千年
的踩踏已使得这些石板如同镜子般平整光滑。十来个僧人正在练习武技。
南北东三面各有一个练武场。西面是研习武功用的罗汉九部。
LONG );
	set("exits", ([
		"east"  : __DIR__"lwc15",
                "west"  : __DIR__"brtang",
		"north" : __DIR__"lwc14",
		"south" : __DIR__"lwc17",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1850);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

