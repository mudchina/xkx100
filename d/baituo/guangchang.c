// Room: /d/baituo/guangchang.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "广场");
	set("long", @LONG
这里是一块不小的广场，上面堆着农家晒的谷物。北上是『白驼山
庄』。东面有间小农舍，西边有块菜地，东南方是一座小桥。
LONG	);
	set("outdoors", "baituo");
	set("exits", ([
		"east"      : __DIR__"nongshe",
		"northup"   : __DIR__"shijie",
		"northwest" : __DIR__"shanlu",
		"southeast" : __DIR__"bridge",
	]));
	set("objects",([
		__DIR__"npc/kid" : 2,
	]));
	set("coor/x", -50010);
	set("coor/y", 19990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
