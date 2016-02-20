// Room: /d/huanggong/jingyunmen.c

inherit ROOM;

void create()
{
	set("short", "景运门");
	set("long", @LONG
此门是通往宫外东路的大门. 外东路是太上皇的居所. 景运门外空
地上有一座箭亭, 又称紫金箭亭, 皇上常在这和王公大臣们一齐射箭, 
操练武艺。
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 6 */
		 "northwest" : __DIR__"qianqingmen",
		 "southwest" : __DIR__"baohedian",
		 "south"     : __DIR__"yongxiang4",
		 "east"      : __DIR__"jianting",
	]));
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 5270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}