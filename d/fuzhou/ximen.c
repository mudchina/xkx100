// Room: /d/fuzhou/ximen.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "西门");
	set("long", @LONG
这里是福州西门。一条笔直的官道向西延伸，直到西边闽江大拐弯
处，官道便转入北岸山坳处，直达中原。
LONG );
	set("exits", ([
		"east" : __DIR__"xixiaojie",
		"west" : "/d/yanping/guandao1",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1810);
	set("coor/y", -6300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
