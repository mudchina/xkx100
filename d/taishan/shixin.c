// Room: /d/taishan/shixin.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "试心石");
	set("long", @LONG
这里便是莲花峰的峰顶，由两块巨石勾连在一起，据说若果你心存
诚意，登上试心石时石块便不会动摇，反之则摇动不止。
LONG );
	set("exits", ([
		"southdown" : __DIR__"lianhua",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 430);
	set("coor/y", 630);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}
