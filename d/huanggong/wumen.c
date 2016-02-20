// Room: /d/huanggong/wumen.c

inherit ROOM;

void create()
{
	set("short", "午门");
	set("long", @LONG
午门是紫禁城的正门，是皇帝送军出征和受降的地方。五丈高的暗
红色城墙上，建有五座崇楼，因此俗称“五凤楼”。台上正中是个大门
楼，进深五间，面阔九间，呈“九五”格局。下有五个门洞，重檐庑殿
顶。城门主楼凹进，两翼张出，东西四座重檐四角攒顶式方形阙亭，以
十三廊庑联接，辅翼着正楼，形如雁翅，气势巍峨。
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 4 */
		"west"  : __DIR__"dao10",
		"east"  : __DIR__"dao1",
		"south" : __DIR__"dianwai",
		"north" : __DIR__"taihemen",
	]));
	set("objects", ([
		__DIR__"npc/yulin" : 2,
		__DIR__"npc/fuchun" : 1,
	]));

	set("coor/x", -200);
	set("coor/y", 5210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}