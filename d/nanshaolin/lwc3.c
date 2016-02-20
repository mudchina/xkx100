// Room: /d/nanshaolin/lwc3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是少林寺的练武场。由无数块巨大的花岗岩石板铺就。上千年
的踩踏已使得这些石板如同镜子般平整光滑。十来个僧人正在练习武技。东南西
三面各有一练武场。
LONG );
	set("exits", ([
		"east"  : __DIR__"lwc2",
		"west"  : __DIR__"lwc4",
		"south" : __DIR__"lwc5",
	]));
	set("objects",([
		__DIR__"obj/zhuang" : 1,
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1780);
	set("coor/y", -6230);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

