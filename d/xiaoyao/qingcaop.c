// qingcaop.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
        set("short", "青草坪");
        set("long", @LONG
这里是树林中的一片比较大的空地，名曰：青草坪。因为处于密林
之中所以这里平时很少有人来，但是不知道为什么，这里却经常有人迹
出现。你看，又一个来了。
LONG );
	set("exits", ([
		"north" : __DIR__"xiaodao3",
		"south" : __DIR__"xiaodao5",
		"east" : __DIR__"xiaodao4",
		"west" : __DIR__"xiaodao1",
	]));
	set("outdoors", "xiaoyao");
	set("objects", ([
		CLASS_D("xiaoyao")+"/suxinghe": 1,
//		__DIR__"npc/xue": 1,
	]));
	set("valid_startroom", 1);
//	set("no_clean_up", 0);
	set("coor/x", 80);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
	"/clone/board/xiaoyao_b"->foo();
}