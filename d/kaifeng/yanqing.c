// /kaifeng/yanqing.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "延庆观");
	set("long", @LONG
延庆观飞檐挑拱，气势磅礴。始建于元太宗五年，原名为重阳观，
为纪念道教中全真教创始人王吉在此传教并逝世于此而修建。明洪武六
年，改名延庆观。
LONG);
	set("exits", ([
		"east"  : __DIR__"wroad2",
		"north" : __DIR__"sanqing",
	]));
	set("objects", ([
		__DIR__"npc/walker" : 1,
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
