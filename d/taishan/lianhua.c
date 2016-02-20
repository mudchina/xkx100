// Room: /d/taishan/lianhua.c
// Last Modified by Winder on Aug. 25 2001
inherit ROOM;

void create()
{
	set("short", "莲花峰");
	set("long", @LONG
莲花峰其实是由五座山峰攒簇而成，状如莲花，因以为名。东面有
危崖万仞，叫五花崖。登上莲花峰后，可看到在盘道中的游人如小蚁般
往来穿梭，故此莲花峰又叫望人峰。往上走便是莲花峰的峰顶。
LONG );
	set("exits", ([
		"northup" : __DIR__"shixin",
		"westup"  : __DIR__"tianjie",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 430);
	set("coor/y", 620);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
