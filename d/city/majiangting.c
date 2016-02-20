// Room: majiangting.c
// Last Modified by winder on Aug. 18 2002

inherit ROOM;

void create()
{
	set("short", "麻将厅");
	set("long", @LONG
麻将厅里显得十分安静，偶尔从房间里传出洗牌的声音。大家都压
低了嗓子说话，似乎每圈输赢都关系着什么似的。东西两间是美女陪伴
的练兵场，玩家想自己对决，就到南间去吧。
LONG );
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"majiangroom1",
		"east"  : __DIR__"majiangroom2",
		"north" : __DIR__"zoulang1",
		"south" : __DIR__"majiangroom",
	]));

	set("coor/x", 20);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
