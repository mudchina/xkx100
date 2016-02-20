// Room: /d/taishan/baiyun.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "白云洞");
	set("long", @LONG
白云洞，又名云窝，因地处悬崖，下有绝涧，危岩多窍、白云缭绕
而名。洞内明人题“卧云”、“锁云”，洞南深谷峻削，名百丈崖。
LONG );
	set("exits", ([
		"eastup" : __DIR__"xiangshan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 760);
	set("coor/z", 200);
	setup();
	replace_program(ROOM);
}
