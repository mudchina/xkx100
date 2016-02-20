// huroom.c
inherit ROOM;

void create()
{
	set("short", "医居");
	set("long", @LONG
你走进了烈火旗的大院后进，这里是个很宁静的小屋。四周摆了不
少医学典籍，还有很多散落堆放的膏、丸、散等。一个老头在此呆呆出
神，似乎有无限心事。
LONG );
	set("exits", ([
		"out" : __DIR__"lhqyuan",
	]));
	set("objects", ([
		__DIR__"npc/hu" : 1,
	]));
	set("outdoors", "mingjiao");
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("coor/x", -52030);
	set("coor/y", 990);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}