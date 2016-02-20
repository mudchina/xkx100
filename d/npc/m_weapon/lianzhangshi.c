// ROOM lianzhangshi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "杖场");
	set("long", @LONG
这里是玄兵古洞的造杖的地方。四周道也不是十分荒凉，相反还可
说有几分景致。露天放着一个巨大的炉子，冒着蓬蓬的蓝炎，似乎什么
都能被它融化似的。
LONG );
	set("exits", ([
		"eastup" : "/d/baituo/xiaolu4",
	]));
	set("objects", ([
		__DIR__"npc/shizhang" :1,
	]));
	set("coor/x", -49970);
	set("coor/y", 20020);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
