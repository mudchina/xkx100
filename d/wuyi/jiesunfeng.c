// Room: /d/wuyi/jiesunfeng.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "接笋峰");
	set("long", @LONG
“凤髓鸾胶天上有，世人休作等闲看”。接笋峰贴壁而立，三道裂
痕清晰可见，仿佛三块岩石粘合而成，似有摇摇欲坠之态，令人望而生
畏。它又称小隐屏，峭削无比，尖锐直上，形同立笋。横裂三痕，仿佛
续界而成，奇妙而险峻。
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"shaibuyan",
		"south" : __DIR__"yunwo",
	]));
	set("objects", ([
		"/d/taishan/npc/dao-ke" : 1,
	]));
	set("coor/x", 1360);
	set("coor/y", -5000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

