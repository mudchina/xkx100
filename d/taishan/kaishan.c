// Room: /d/taishan/kaishan.c
// Last Modified by winder on Aug. 25 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "开山");
	set("long", @LONG
对松山北，高阜之上，双崖夹道，旧称云门，今名开山，为清乾隆末
年改建盘道时所辟。这里便是泰山十八盘的起点。此处向上，直到龙门，
被称之为“慢十八盘”。
LONG );
	set("exits", ([
		"northup"   : __DIR__"man18",
		"southdown" : __DIR__"duisong",
	]));
	set("objects", ([
		CLASS_D("taishan")+"/first" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 710);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}
