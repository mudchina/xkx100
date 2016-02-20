// Room: /d/huanggong/humen.c

inherit ROOM;

void create()
{
	set("short", "白虎门");
	set("long", @LONG
白虎门, 皇城西门. 由此西通狩场, 东往内城. 少有人来人往, 但
依旧森严戒备. 前些年正是在这发生民乱, 险些让暴民闯进了内宫, 所
以, 这儿的守备之严较其他各城门有过之而无不及.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"dadao",
		"east" : __DIR__"xihuamen",
	]));
	set("no_clean_up", 0);

	set("objects", ([
		__DIR__"npc/yulin" : 2,
	]));
	set("coor/x", -240);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}