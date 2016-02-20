// /kaifeng/zhulin0.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set ("short", "竹林");
	set ("long", @LONG
一阵清凉从头顶碧绿的竹梢倾斜下来，几点金色的光斑透过竹叶在
地上跳动，风过处，刷刷的声响随风而远去，在竹林的中间被人开出了
一片空地，中央是一间小茅屋。
LONG);

	set("outdoors", "kaifeng");
	set("exits", ([
		"enter" : __DIR__"zhulin1",
		"west":__DIR__"fanta",
	]));
	setup();
	replace_program(ROOM);
}
