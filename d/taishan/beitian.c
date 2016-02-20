// Room: /d/taishan/beitian.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "北天门");
	set("long", @LONG
这里位于石马山的北麓，是岱顶的北面出口，路口有一石坊，上面
写着「玄武」二字。
LONG );
	set("exits", ([
		"southdown" : __DIR__"zhangren",
	]));
	set("objects", ([
		CLASS_D("taishan")+"/yujizi" : 1,
	]));
	set("outdoors", "taishan");
	set("coor/x", 350);
	set("coor/y", 800);
	set("coor/z", 220);
	setup();
	replace_program(ROOM);
}
