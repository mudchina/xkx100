// Room: /d/songshan/chitang.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "池塘");
	set("long", @LONG
你扶着塘边的石栏杆往南望，可以看到剑池的那口大铁剑，回身就
是小花园了。嵩岳绝顶，天风浩荡，吹皱一池碧水，大略韵味如此。
LONG );
	set("exits", ([
		"north" : __DIR__"huayuan",
	]));
	set("outdoors", "songshan");
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 910);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
