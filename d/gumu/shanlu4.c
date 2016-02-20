// shanlu4.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这条山路盘着终南山主峰而上，山路贴着石璧凿出，只容许一人得
过，形势极为险峻。往远处望去。群山环绕，列於脚下，百里美景尽收
眼底，顿时令人豪气陡声，想要长啸一声。往东下和西上各是一条山路。
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"westup"   : __DIR__"shanlu3",
		"eastdown" : __DIR__"shanlu5",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", 120);
	set("coor/z", 160);
	setup();
	replace_program(ROOM);
}
