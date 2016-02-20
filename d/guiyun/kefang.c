// Room: /d/guiyun/kefang.c
// Last Modified by winder on Jul. 9 2001

inherit ROOM;

void create()
{
	set("short","客房");
	set("long",@LONG
这是归云庄招待客人住宿的房间。室内陈设精雅，两床相对，枕衾
雅洁。北面窗外是一个大花园，江南景致，尽在其中。
LONG
);
	set("exits",([
		"south" : __DIR__"zoulang2",
	]) );
	set("no_clean_up", 0);
	set("sleep_room", 1);
	setup();
	replace_program(ROOM);
}
