// Room: /d/quanzhou/shanlu2.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是清源山区的碎石小径，曲折蜿蜒，两旁林木茂盛，遮天蔽日。
满径落叶，柔软稀松。虫鸟啾啾。凉风习习。
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"southdown" : __DIR__"shanlu3",
		"northup"   : __DIR__"huruquan",
		"westup"    : __DIR__"liandanshi",
	]));
	set("objects", ([
		"/d/village/npc/dog" : 1,
	]));
	set("coor/x", 1850);
	set("coor/y", -6410);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
