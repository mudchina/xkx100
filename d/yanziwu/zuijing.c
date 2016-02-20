//ROOM: /d/yanziwu/zuijing.c

inherit ROOM;

void create()
{
	set("short", "缀锦楼");
	set("long",@LONG
地面铺着大红地毯，房中布置得珠光宝气，各种珠宝，古玩摆放得
琳琅满目，你看了颇为心动，很想顺手拿走几件，但又有些不敢。角落
里有一架红木楼梯。
LONG );
	set("exits", ([
		"west" : __DIR__"canheju",
		"east" : __DIR__"jiashan",
	]));
	set("no_clean_up", 0);
	set("coor/x", 830);
	set("coor/y", -1540);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}