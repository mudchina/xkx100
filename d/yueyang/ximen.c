// Room: /d/yueyang/ximen.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "岳阳西门");
	set("long", @LONG
这里是岳阳城楼的西门，门内也没有官兵看守，大概这里是丐帮的
天下，岳阳府城的治安也就实质上给丐帮接管了。官府也不大关心如何
如何的，反正只要丐帮合作，倒也路不拾遗、夜不闭户的。
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"east"     : __DIR__"xijie",
		"northup"  : __DIR__"loumen",
		"westdown" : __DIR__"shijie7",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/xiang" : 1,
	]));
	set("coor/x", -1430);
	set("coor/y", -2270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
