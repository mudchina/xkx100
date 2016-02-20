// Room: /d/fuzhou/xidajie1.c
// may. 12 1998 Java

inherit ROOM;

void create()
{
	set("short", "西大街");
	set("long", @LONG
这里是福州老城的西大街。大街两旁三三两两几位小贩正在叫卖，
街的南边就是南后街了。
LONG );

	set("exits", ([
		"east"  : __DIR__"dongjiekou",
		"west"  : __DIR__"xidajie",
		"south" : __DIR__"nanhoujie1",
	]));
	set("objects", ([
		__DIR__"npc/xiaofan" : 1,
	]));
	set("outdoors", "fuzhou");
	set("coor/x", 1835);
	set("coor/y", -6300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
