// Room: /d/quanzhou/guangchang.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "中心广场");
	set("long", @LONG
这是泉州的中心地带，树荫浓郁，整齐划一。广场中人山人海，摩
肩接踵，来来往往的人群中时常可见不同肤色的胡人。泉州因其广植刺
桐树，又名「刺桐城」，是「海上丝绸之路」的起点。数以万计的外国
商贾、使节和宗教信徒远涉重洋来到此地，其中不少人就定居于此。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"eastroad1",
		"west"  : __DIR__"westroad1",
		"south" : __DIR__"southroad1",
		"north" : __DIR__"northroad1",
	]));
	set("objects", ([
		__DIR__"npc/huren" : 1,
		__DIR__"npc/xiaofan" : 1,
		"/d/city/npc/liumangtou" : 1,
	]));
	set("coor/x", 1850);
	set("coor/y", -6530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
