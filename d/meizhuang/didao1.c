// /d/meizhuang/didao1.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "梅庄密道");
	set("long", @LONG
这是一条昏暗潮湿的地道，地道很长，两边点着两根不太明亮的火
把，地道两旁的墙壁上画着很多不知道出自何人之手的壁画，而且画得
相当难看，你加快脚步，想知道地道的尽头是什么地方。 
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"didao2",
		"east"  : __DIR__"didao1",
		"south" : __DIR__"didao3",
		"north" : __DIR__"didao2",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3490);
	set("coor/y", -1470);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
