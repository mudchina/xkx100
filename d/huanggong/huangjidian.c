// Room: /d/huanggong/huangjidian.c

inherit ROOM;

void create()
{
	set("short", "皇极殿");
	set("long", @LONG
这里是宫中仅次于御花园的乾隆花园的中心。皇极殿前是宁寿门，
后通宁寿宫，就是俗称“外东路”的太上皇修身怡性处。
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([
		"north"     : __DIR__"ningshougong",
		"south"     : __DIR__"ningshoumen",
	]));
	set("no_clean_up", 0);
	set("coor/x", -180);
	set("coor/y", 5200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}