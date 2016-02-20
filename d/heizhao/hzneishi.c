// Room: /heizhao/hzneishi.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "黑沼内室");
	set("long", @LONG
内室墙壁围成圆形，地下满铺细沙，沙上画着许多横直符号和
圆圈，又写着些“太”、“天元”、“地元”、“人元”、“物元
”等字。你看着地下符字，尽是些术数中的难题，是算经中的“天
元之术”。
LONG );
	set("no_clean_up", 0);

	set("exits", ([
		"south" : __DIR__"hzneitang",
	]));
	set("coor/x", -5100);
	set("coor/y", -1470);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}