inherit ROOM;

void create()
{
	set("short", "马棚");
	set("long", @LONG
这里是康亲王府的马棚，其中好马无数。刚一进门，马儿就冲你“
恢恢”直叫。
LONG );
	set("exits", ([
		"west" : __DIR__"kang3",
	]));
	set("objects", ([
		__DIR__"npc/yucongma" : 1,
	]));
	set("coor/x", -179);
	set("coor/y", 4082);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
