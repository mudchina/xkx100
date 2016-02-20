// liangong.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "石屋");
	set("long", @LONG
这是树林中的一间石屋，屋内显得什么清净和简朴，房间中除了一
副棋盘外，并没有什么特别的摆设在这里，不会受到任何东西的骚扰，
是个修炼内功的好地方。
LONG );
	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"xiaodao4",
	]));
	set("objects", ([ /* sizeof() == 2 */
		CLASS_D("xiaoyao")+"/fanbailing" : 1,
	]));
	set("coor/x", 90);
	set("coor/y", -490);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}