// Room: /d/taishan/sanyibai.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "三义柏");
	set("long", @LONG
万仙楼位于红门宫北，楼前有古柏三株，挺拔并列，苍翠凌云，碣
书“三义柏”。再前西崖题“勇登仙境”，下有洞，洞内有石龟，俗称
龟洞。
LONG );
	set("exits", ([
		"north"     : __DIR__"wanxianlou",
		"southdown" : __DIR__"yitian",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 570);
	set("coor/z", 40);
	setup();
	replace_program(ROOM);
}
