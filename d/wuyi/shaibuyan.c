// Room: /d/wuyi/shaibuyan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "晒布岩");
	set("long", @LONG
晒布岩位于六曲溪畔，天游峰下。岩如刀切斧劈一般，直上直下，
阔大平坦，高近二百丈。每当夕阳西照，岩壁水刷痕迹愈发分明，宛若
仙人晒布。相传挑担大脚仙挑着织女的云锦，贪图武夷美景，结果云锦
露湿，便在此晒布。不意到了中午，烈日晒化锦缎，连大仙接云锦的手
印也留在岩壁上了。所以又名“仙掌峰”。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"jiesunfeng",
		"northeast" : __DIR__"chadong",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1360);
	set("coor/y", -4990);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

