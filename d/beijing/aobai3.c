// /d/beijing/aobai3.c
// Last Modified by winder on Jan. 18 2002

inherit ROOM;

void create()
{
	set("short", "鳌府大院");
	set("long", @LONG
你走进大院，迎面是一个假山水池，池中立着一块巨大无比的翡翠，
显然是鳌拜收刮来的宝物。水池的两旁种满了花草。北边是厨房，有一
棵槐树，郁郁葱葱，遮盖了大半个院子，显得阴森恐怖。西边一条长廊
走道通往后院，有几个官兵把守。
LONG );
	set("outdoors", "beijing");
	set("exits", ([
		"west"  : __DIR__"aobai4",
		"east"  : __DIR__"aobai2",
		"north" : __DIR__"aobai5",
	]));
	set("objects", ([
		__DIR__"npc/wuzhirong" : 1,
	]));
	set("coor/x", -201);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
