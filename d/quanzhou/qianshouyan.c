// Room: /d/quanzhou/qianshouyan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "千手岩");
	set("long", @LONG
沿山路而上，即达千手岩。这里每交秋冬满山枫叶，如火如锦，煞
是好看。岩上一寺，内供观音坐像一尊。寺前苍松挺拔，寺后峰石嶙峋，
别有一番景致。近旁就是著名高僧弘一法师的墓亭，墓亭边的崖石上刻
着他临终时写的「悲欣交集」四个字。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast" : __DIR__"mituoyan",
		"northup"   : __DIR__"laojunyan",
	]));
	set("coor/x", 1820);
	set("coor/y", -6390);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
