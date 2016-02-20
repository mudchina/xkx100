// /d/quanzhen/puguangsi.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "普光寺");
	set("long", @LONG
这是一个位於终南山下的小寺庙，庙门横额写着 "普光寺" 三个
大字。由於此庙是上终南山的必经之路，大多数的游客都会在此落脚
休息，也因此此处香火也颇为鼎盛。庙前的几株松树下，立着一块石
碑(shibei)，几乎快被周围的长草给遮掩了。往西走是一条小路.
LONG
	);
	set("outdoors", "zhongnan");
	set("exits", ([
		"west" : __DIR__"shanlu4",
	]));

	set("coor/x", -3120);
	set("coor/y", 0);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
