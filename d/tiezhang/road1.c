// Room: /d/tiezhang/road1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "黄土路");
	set("long", @LONG
你走在一条尘土飞扬的黄土路上，两旁是阴森森的树林。这里是川
湘交界，据说经常有土匪出没，不可久留。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"southwest" : __DIR__"road2",
		"northeast" : __DIR__"lx",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x", -2010);
	set("coor/y", -2010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}