// Room: /d/mobei/shulin4.c
// Last Modified by winder on May. 25 2001

inherit ROOM;

void create()
{
	set("short", "杂树林");
	set("long", @LONG
在漠北这片苦寒的土地上，这片杂树林宛如沙漠中的绿州般令人惊
喜。林子不大，树木也比较矮小，许多地方的灌木丛把路完全挡住了，
树上残留的几片叶子在风中轻轻飘落。
LONG);
	set("outdoors","mobei");
	set("exits", ([ /* sizeof() == 2 */
		"east"   : __DIR__"shulin1",
		"westup" : __DIR__"xiaolu",
	]));
	set("no_clean_up", 0);
	set("coor/x", -240);
	set("coor/y", 5200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
