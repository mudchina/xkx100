// /d/beijing/alley2.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "杨柳胡同");
	set("long", @LONG
街道上一个人也看不到。你突然有点害怕起来。东南边有一家棺材
店。西南边是一条黑漆漆的小巷，你不知道要不要继续向里走。“还是
往北回去吧，免得。。。。。。”，心底里一个声音不住地对你说。
LONG );
	set("outdoors", "beijing");

	set("exits", ([
		"north"     : __DIR__"alley1",
		"southeast" : __DIR__"guancai1",
		"southwest" : __DIR__"alley3",
	]));
	set("no_clean_up", 0);

	set("coor/x", -220);
	set("coor/y", 4020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
