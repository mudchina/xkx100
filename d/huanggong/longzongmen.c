// Room: /d/huanggong/longzongmen.c

inherit ROOM;

void create()
{
	set("short", "隆宗门");
	set("long", @LONG
此门是通往宫外西路的大门. 外西路是太后的居所. 隆宗门外就是
慈宁宫了.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([ /* sizeof() == 6 */
		 "northeast" : __DIR__"qianqingmen",
		 "southeast" : __DIR__"baohedian",
		 "south"     : __DIR__"yongxiang1",
		 "west"      : __DIR__"ciningmen",
	]));
	set("no_clean_up", 0);

	set("coor/x", -210);
	set("coor/y", 5270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}