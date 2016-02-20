// /yubifeng/xiaolu2.c
// Last modified by winder 2003.9.2

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
这是一条在丘峦起伏的小小山脉下的小路，两边是稀疏的松树，夹
杂着班驳的积雪。偶尔狂风大作，松果和雪团交加而下。雪地上有不少
脚印，看来似乎是刚有野兽走过。
LONG );
	set("exits", ([
		"west"  : __DIR__"xiaolu3",
		"north" : __DIR__"xiaolu1",
	]));
	set("objects", ([
		"/d/baituo/obj/chai" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "yubifeng");
	set("coor/x", 6110);
	set("coor/y", 5140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
