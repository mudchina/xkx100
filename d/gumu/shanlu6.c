// shanlu6.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这条山路盘着终南山主峰而上，山路贴着石璧凿出，只容许一人得
过，形势极为险峻。往远处望去。群山环绕，列於脚下，百里美景尽收
眼底，顿时令人豪气陡声，想要长啸一声。往东下和北上各是一条山路。
往南下是白马潭。
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"northup"   : __DIR__"shanlu5",
		"eastdown"  : "/d/quanzhen/shanlu13",
		"southdown" : __DIR__"baimatang",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3190);
	set("coor/y", 110);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}
