// Room: paixiting.c
// Last Modified by winder on Aug. 18 2002

inherit ROOM;

void create()
{
	set("short", "牌戏厅");
	set("long", @LONG
这里是牌戏厅。周围的各个房间的门都虚掩着，里面烟雾缭绕。看
来正在上瘾。你轻轻贴近房门，就可以清晰地听到纸牌砸在桌面上的声
音，夹杂着偶尔响起的起哄声。
LONG );
	set("no_fight", "1");
	set("no_beg", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("no_clean_up", 0);
	set("exits", ([
		"west"  : __DIR__"yapairoom",
		"east"  : __DIR__"pai9room",
		"south" : __DIR__"zoulang1",
		"north" : __DIR__"gongzhuroom",
	]));

	set("coor/x", 20);
	set("coor/y", 9);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
