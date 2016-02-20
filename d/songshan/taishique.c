// Room: /d/songshan/taishique.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "太室阙");
	set("long", @LONG
嵩山古称方外，又称崇山，为五岳中的中岳，由太室少室二山沿绵
而成。汉武帝时称“嵩高”，取自诗经“嵩岳维高，峻极于天”，道教
以之为第六小洞天。阕高丈余，南面刻“中岳太室阳城”六字，篆文古
朴，苍劲有力。向西就是去少室山少林寺的路。向北一里许便是中岳庙
了。
LONG );
	set("exits", ([
		"north" : __DIR__"tianzhongge",
		"south" : "/d/kaifeng/shanlu2",
		"east"  : "/d/nanyang/ruzhou",
		"west"  : "/d/shaolin/shijie1",
	]));
	set("outdoors", "songshan");
	set("objects", ([
		__DIR__"npc/dizi" : 1,
		"/clone/misc/dache" : 1,
	]));
	set("coor/x", 0);
	set("coor/y", 700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
