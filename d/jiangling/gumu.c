//Edited by fandog, 02/15/2000
inherit ROOM;
void create()
{
    set("short", "古墓");
    set("long",@LONG
这里阴森森的象是个古代的墓室，一阵阴风吹来，你不由得打了个
寒噤。以前可能有盗墓的人来过，到处是碎瓷片和破纸片，地上有个黑
黝黝的木盒，也不知里面装了甚么古怪东西。
LONG);
	set("exits", ([
		"up" : __DIR__"shangang2",
	]));
	set("objects", ([
		__DIR__"obj/muhe"    : 1,
	]));
	set("coor/x", -1490);
	set("coor/y", -2050);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}