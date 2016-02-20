// Room: /city/biaojuhy.c

inherit ROOM;

void create()
{
	set("short", "后院");
	set("long", @LONG
这里是镖局伙计们辛苦之余，休息放松的院子。院子的中央横七竖
八的架着几根竹竿，想必是用来晾晒衣服的。院子的周围有几间小房，
是平时镖师伙计们休息的所在。
LONG );
	set("exits", ([
		"south" : __DIR__"biaojuzt",
		"north" : __DIR__"biaojucf",
		"east"  : __DIR__"biaojuxf",
		"west"  : __DIR__"biaojuxf1",
	]));
	set("objects", ([
		__DIR__"npc/zheng" : 1,
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 1830);
	set("coor/y", -6296);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
