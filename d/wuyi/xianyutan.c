// Room: /d/wuyi/xianyutan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "仙浴潭");
	set("long", @LONG
高耸的石壁，营造了一个幽雅深邃的意境。一塘清澈的池水闪着粼
粼的波光。夏日的炎热早就溶进雪花泉的淙淙碧流水响中。当你步下天
游峰的仙浴潭，疲倦的身心顿然有了真切的抚慰，烦恼与忧虑不觉淡化
成浅浅的宁静心境。这，也许就是仙人与凡人的区别吧？超然物外的仙
人没有凡人摆脱不了的远虑近忧。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest" : __DIR__"tianyoufeng",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1390);
	set("coor/y", -4960);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

