// fangjian1.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
        set("short", "房间");
        set("long", @LONG
可以看出这里以前曾经是一个下棋的地方，房间除了一张石几，两
只软椅之外，空荡荡的一无所有，石几上刻着纵横十九道棋路，棋局上
布着二百多颗棋子，却是黑白对峙，竟然是一局没有下完的棋。
LONG );
	set("exits", ([
		"south" : __DIR__"shiji1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50030);
	set("coor/y", -21030);
	set("coor/z", -40);
	setup();
	replace_program(ROOM);
}