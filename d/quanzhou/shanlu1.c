// Room: /d/quanzhou/shanlu1.c
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
		"southup"   : __DIR__"qingyuandong",
		"northdown" : __DIR__"anpingqiao",
	]));
	set("objects", ([
		__DIR__"npc/banjiu" : 1,
	]));
	set("coor/x", 1840);
	set("coor/y", -6370);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
