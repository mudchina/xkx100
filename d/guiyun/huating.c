// Room: /guiyun/huating.c
// Date: Nov.18 1998 by Winder

inherit ROOM;

void create()
{
	set("short", "花厅");
	set("long", @LONG
这是一间四方型的厅亭，没有牌匾，正面两方木柱，柱上挂了幅缺
了半阙的『诗词』(poem)。厅内摆设了几张桌椅。一个丫环正
在抹拭桌面。
LONG );
	set("outdoors", "guiyun");
	set("exits", ([
		"west"  : __DIR__"zoulang8",
		"south" : __DIR__"zoulang7",
	]));
	set("item_desc", ([
		"poem" :
"
      ┌─┐             ┌─┐
      │兵│             │  │
      │火│             │  │
      │有│             │  │
      │馀│             │  │
      │烬│             │  │
      │贫│             │  │
      │村│             │  │
      │才│             │  │
      │数│             │  │
      │家│             │  │
      └─┘             └─┘
",
	]));
	set("objects", ([
		__DIR__"npc/xiaolan" : 1,
	]));
	set("coor/x", 300);
	set("coor/y", -560);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

