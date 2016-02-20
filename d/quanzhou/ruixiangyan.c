// Room: /d/quanzhou/ruixiangyan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "瑞象岩");
	set("long", @LONG
这是座落在半山腰的小峡谷中的一块石坪。登上此处，即可见一座
漂亮的仿木石室。石室后高耸的大岩石叫作「天柱峰」。古时一位巧匠
将其雕成「释迦牟尼」瑞象，作立状，神像庄严大方，维妙维肖。
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"southup"     : __DIR__"wangzhouting",
		"northdown"   : __DIR__"shanlu3",
	]));
	set("objects", ([
		"/d/wudang/npc/monkey" : 1,
	]));
	set("coor/x", 1850);
	set("coor/y", -6430);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
