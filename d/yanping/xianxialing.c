// Room: /d/yanping/xianxialing.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "仙霞岭");
	set("long", @LONG
这里就是闽浙分水的仙霞岭。向阳的坡面郁郁葱葱，长满了长长的
马尾松。沿途的山路十分难行，来往的口音也渐渐带有闽音，越来越难
以辩识了。
LONG );
	set("exits", ([
		"northdown" : "/d/jiaxing/jnroad4",
		"south"     : __DIR__"erbapu",
	]));
	set("objects", ([
		"/d/wudang/npc/yetu" : 2,
	]));
	set("outdoors", "jiangnan");
	set("coor/x", 1500);
	set("coor/y", -3000);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
