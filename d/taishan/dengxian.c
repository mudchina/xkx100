// Room: /d/taishan/dengxian.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "登仙桥");
	set("long", @LONG
登仙桥，俗称东西桥子，就在天绅岩北。桥西南遍地红沙石，名红
沙岭。桥北东侧有古洞如棚，可以容马，明代吴维岳大书“歇马崖”。
旧传吕洞宾曾在此崖上留墨。
LONG );
	set("exits", ([
		"south" : __DIR__"tianshen",
		"north" : __DIR__"baidong",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 620);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}
