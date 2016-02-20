// Room: /d/huanggong/nanxundian.c

inherit ROOM;

void create()
{
	set("short", "南熏殿");
	set("long", @LONG
南熏殿里的木构, 藻井和天花, 彩画均极富丽. 凡立新帝, 都要在
这里给其母后上尊号, 并举行册封大典, 阁臣在此写金宝册. 这里存着
历代帝后及先圣名贤的图像.
LONG
	);
	set("exits", ([
		"north"     : __DIR__"wuying",
	]));
	set("no_clean_up", 0);
	set("coor/x", -220);
	set("coor/y", 5250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}