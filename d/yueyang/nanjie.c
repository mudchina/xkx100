// Room: /d/yueyang/nanjie.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "南街");
	set("long", @LONG
这是一条又长又宽的青石大道，东边是客店，西边是饭店，这里是
南来北往的客商必到之处，因此也是全城最热闹的地方。两边的小二在
屋檐下不停地招揽生意，一些流氓和不成器的乞丐们也混在其中乘机揩
油，大姑娘喊，小媳妇闹，响成一片。
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"kedian",
		"west"  : __DIR__"jiudian",
		"north" : __DIR__"zhongxin",
		"south" : __DIR__"nanmen",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/liu-zhuzhuang" : 1,
	]));
	set("coor/x", -1410);
	set("coor/y", -2280);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
