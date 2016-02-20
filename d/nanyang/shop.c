// Room: /d/nanyang/shop.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;
void create()
{
	set("short","商号");
	set("long",@LONG
一间不大的店铺，进门就是一个黄柏木未涂漆的柜台，虽然擦拭得
很干净，但是显见是多年之物了，木质都已作深黄。上面一把算盘，一
个茶吊。柜台一侧陈列着些杂饰，玉板，银环，珠簪，折扇，应有尽有。
墙上挂着几幅字画。
LONG);
	set("exits",([
		"east"  : __DIR__"dajie1",
	]));
	set("objects",([
		__DIR__"npc/boss" : 1,
	]));
	set("coor/x", 0);
	set("coor/y", 490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
