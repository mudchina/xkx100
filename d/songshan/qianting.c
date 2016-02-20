// Room: /d/songshan/qianting.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "前庭");
	set("long", @LONG
这里是峻极禅院山门内前庭。庭院中青石铺地、古柏森森，可容纳
数百人集会。内里是禅院大殿，两厢是一些低矮小房。
LONG );
	set("exits", ([
		"north"     : __DIR__"chanyuan",
		"southdown" : __DIR__"junjigate",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/shi" : 1,
		CLASS_D("songshan")+"/di" : 1,
	]));
	set("outdoors", "songshan");
	set("coor/x", -20);
	set("coor/y", 860);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
