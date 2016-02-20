// Room: /d/huanggong/huangjimen.c

inherit ROOM;

void create()
{
	set("short", "皇极门");
	set("long", @LONG
皇极殿庭院的大门. 由此往北, 是皇帝休憩和太上皇养老饴孙的地
方, 俗称 "外东路" . 门前就是享誉海内外的九龙壁了.
LONG
	);
	set("outdoors", "huanggong");
	set("exits", ([
		"north"     : __DIR__"ningshoumen",
		"south"     : __DIR__"jianting",
		"west"      : __DIR__"yuqinggong",
	]));
	set("no_clean_up", 0);
	set("coor/x", -180);
	set("coor/y", 5180);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}