// Room: /wuliang/road4.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "甬道");
	set("long", @LONG
这里是剑湖宫内最长的甬道。甬道绕山势曲折延展，南通正厅，
北面就是无量剑掌门人的居所剑湖宫了。
LONG );
        set("outdoors", "wuliang");
	set("no_clean_up", 0);
	set("exits", ([
		"northup"  : __DIR__"jianhugong",
		"south"    : __DIR__"zhengting",
	]));
	set("coor/x", -71000);
	set("coor/y", -79880);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}