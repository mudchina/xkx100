// shanlu1.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这条山路盘着终南山主峰而上，山路贴着石璧凿出，只容许一人得
过，形势极为险峻。往远处望去。群山环绕，列於脚下，百里美景尽收
眼底，顿时令人豪气陡声，想要长啸一声。往南下是一片空地。往北上
就是终南山主峰。
LONG	);
	set("outdoors", "gumu");
	set("exits", ([
		"southdown" : __DIR__"kongdi",
		"northup"   : __DIR__"zhufeng",
	]));
	set("no_clean_up", 0);
	set("coor/x", -3200);
	set("coor/y", 100);
	set("coor/z", 180);
	setup();
	replace_program(ROOM);
}
