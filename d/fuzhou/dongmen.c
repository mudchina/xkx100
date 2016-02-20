// Room: /d/fuzhou/dongmen.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "东门");
	set("long", @LONG
东门外是福州平原。从这里看去，可以见到密密的丛林。出东门十
里地就是鼓山了。
LONG );
	set("exits", ([
                "east" : __DIR__"shulin",
                "west" : __DIR__"dongxiaojie",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1870);
	set("coor/y", -6300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
