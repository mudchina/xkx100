inherit ROOM;

void create()
{
	set("short", "西客房");
	set("long", @LONG
这里是西客房，一个掌柜和两个伙计躲在角落里瑟瑟发抖。
LONG );
	set("exits", ([
		"east" : __DIR__"kedian2",
	]));
	set("objects", ([
		__DIR__"npc/zhanggui":1,
		__DIR__"npc/huoji":2,
	]));
	set("coor/x", -230);
	set("coor/y", 3990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
