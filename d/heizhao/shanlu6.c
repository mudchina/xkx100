// Room: /heizhao/shanlu6.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
向西走了七八十里，道路愈来愈窄，再行八九里，道路两旁山
峰壁立，中间一条羊肠小径，仅容一人勉强过去。
LONG );
	set("outdoors", "taoyuan");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : "/d/henshan/hsroad6",
		"westup"    : __DIR__"shanlu7",
	]));
	set("coor/x", -5000);
	set("coor/y", -1300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}