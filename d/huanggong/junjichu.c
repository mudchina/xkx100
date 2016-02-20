// Room: /d/huanggong/junjichu.c

inherit ROOM;

void create()
{
	set("short", "军机处");
	set("long", @LONG
这是一排不起眼的房舍. 但这排又矮又小的房子其实非同寻常, 
这是辅佐皇帝的最高政务机构, 以处理西北军务为名的设军机房, 又
名办理军机处.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"southeast" : __DIR__"qianqingmen",
	]));
	set("no_clean_up", 0);

	set("coor/x", -210);
	set("coor/y", 5290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}