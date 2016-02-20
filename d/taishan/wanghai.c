// Room: /d/taishan/wanghai.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "望海石");
	set("long", @LONG
仙人桥南是望海石，巨石坦豁如鸟伏卧，石侧各有一小水槽，每逢
雨后，水顺槽而流 ，如鸟之两翼。明人林古度书刻“双流翼注”，袁洪
愈大书“望海”。
LONG );
	set("exits", ([
		"north"    : __DIR__"xianren",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren" : 5,
	]));
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 740);
	set("coor/z", 210);
	setup();
	replace_program(ROOM);
}
