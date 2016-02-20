// Room: /d/nanshaolin/lwc15
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
这里是少林寺的中心练武场。由无数块巨大的花岗岩石板铺就。上
千年的踩踏已使得这些石板如同镜子般平整光滑。武场中央竖立着一个
金光闪闪的金人，几位老僧神色庄严，脚踏八卦方位围绕，缓缓发招。
LONG );
	set("exits", ([
		"east"  : __DIR__"lwc11",
		"west"  : __DIR__"lwc16",
		"north" : __DIR__"lwc13",
		"south" : __DIR__"lwc18",
	]));
	set("objects",([
		__DIR__"obj/jin-ren" : 1,
	]));
	set("outdoors", "nanshaolin");
	set("coor/x", 1860);
	set("coor/y", -6240);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

