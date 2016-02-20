// Room: /d/yanziwu/tianfeng.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "天风榭");
	set("long", @LONG
天风榭建在蔓陀山峰上，四面镂刻的窗廊，四时风来，凉爽宜人，
号为天风。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"west"   : __DIR__"path24",
	]));
	set("coor/x", 1220);
	set("coor/y", -1250);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}