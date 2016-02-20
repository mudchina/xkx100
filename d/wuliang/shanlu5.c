// Room: /wuliang/shanlu5.c
// Date: Oct.18 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "山坡");
	set("long", @LONG
爬上山坡，山路向下回转进入一个山坳。那一条条的袅袅青烟原
来都是从山坳里冒出来的。这里地势突兀，正是看山景的好去处。不
过行人到此，见了这的人，恐怕都没什么好心情游山玩水了。
LONG );
        set("outdoors", "wuliang");
	set("exits", ([
		"westdown"  : __DIR__"shanlu6",
		"southdown" : __DIR__"shanlu4",
	]));
	set("objects", ([
		__DIR__"npc/shennongdizi" : 2,
	]));
	set("coor/x", -70990);
	set("coor/y", -79980);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}