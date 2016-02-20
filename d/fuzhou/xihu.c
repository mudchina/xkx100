// Room: /d/fuzhou/xihu.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "西湖");
	set("long", @LONG
福州西湖原为灌溉疏浚之利而掘，汇一郭之水以为滋农时。而今，
春水环绿岛，长柳戏游鱼，已有十分景致。
LONG );
	set("exits", ([
		"south" : __DIR__"xixiaojie",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
