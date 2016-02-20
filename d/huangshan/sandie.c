// Room: /d/huangshan/sandie.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "三叠泉");
	set("long", @LONG
虎头岩西北的三叠岩是黄山二奇泉中的一个，因为高山下泄的泉水
流过三个陡坎形成三折而名。无论远观近看，傍着周围清幽的山林，都
是无以伦比的胜境。三叠泉不远是鸣弦泉。
LONG
	);
	set("exits", ([ 
		"southup" : __DIR__"zuishi",
		"north"	  : __DIR__"mingxuan",
	]));
	set("outdoors", "huangshan");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
