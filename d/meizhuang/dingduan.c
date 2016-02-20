// /d/meizhuang/dingduan.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "书架顶部");
	set("long", @LONG
你现在在书架的顶部，从这里你可以看见整个密室的情况，除了几
具白骨以外，确实没有什么值得你怀疑的东西，但你发现书架的顶部非
常不合适的铺着一块红绸。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"mishi",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"obj/hongchou" : 1,
	]));

	set("coor/x", 3490);
	set("coor/y", -1400);
	set("coor/z", 5);
	setup();
	replace_program(ROOM);
}
