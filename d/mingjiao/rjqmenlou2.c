//RJQMENLOU2.C

inherit ROOM;

void create()
{
	set("short", "门楼二层");
	set("long", @LONG
这里是一间大石室，从石窗向外看去，整个院落一览无余，这里正
是一处易守难攻的紧要关隘。右面有一条石梯直通楼上。
LONG );
	set("exits", ([
		"up" : __DIR__"rjqmenlou3",
		"down" : __DIR__"rjqmenlou1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 860);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}