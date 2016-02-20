// /d/meizhuang/qishi.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "棋室");
	set("long", @LONG
这里便是二庄主黑白子的棋室了，棋室里两张石凳，一张石几，石
几上用黑白子的指力刻着纵横九九八十一道，这里除了简单的放着两盒
用玉做成的棋子外，什么都没有，显是怕双方对弈时分心。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east" : __DIR__"zoulang2",
	]));
	set("objects", ([ /* sizeof() == 1 */
		CLASS_D("heimuya")+"/zi" : 1,
	]));
	set("no_clean_up", 0);

	set("coor/x", 3490);
	set("coor/y", -1370);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
