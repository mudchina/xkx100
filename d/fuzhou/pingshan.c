// Room: /d/fuzhou/pingshan.c
// Date: May 12, 98  Java

inherit ROOM;

void create()
{
	set("short", "福州屏山");
	set("long", @LONG
屏山古称越王山，横亘福州城北，山下华林寺，构法考究。屏山上
俯瞰榕城，历历如画。
LONG );
	set("exits", ([
		"southdown" : __DIR__"beidajie",
	]));
	set("outdoors", "fuzhou");
	set("no_clean_up", 0);
	set("coor/x", 1840);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
