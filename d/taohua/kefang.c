// Room: /d/taohua/kefang.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short","客房");
	set("long",@LONG
这里是桃花岛招待客人住宿的房间。室内陈设精雅，两床相对，枕
衾雅洁。窗外透进早春四月的颜色。推窗远处隔着如海的桃花林，就是
桃花岛的两忘峰了。
LONG
);
	set("exits",([
		"west" : __DIR__"jicui",
	]) );
	set("no_clean_up", 0);
	set("sleep_room", 1);
	set("coor/x", 9020);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}