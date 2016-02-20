// Room: /d/huanggong/neigedatang.c

inherit ROOM;

void create()
{
	set("short", "内阁大堂");
	set("long", @LONG
内阁大堂内设典籍库, 主要收集国朝; 档案, 实录和圣训等书.
LONG
	);
	set("exits", ([
		"northeast"  : __DIR__"wenhua",
	]));
	set("no_clean_up", 0);
	set("coor/x", -200);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}