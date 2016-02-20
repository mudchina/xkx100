// /d/beihai/haopu.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "濠濮间");
	set("long", @LONG
东岸之濠濮涧，为三间水榭。北邻画舫斋，东北有迭砌玲珑的山石
环绕。在嶙峋山石间有一泓池水，池中有敞轩、曲桥、回旋变化于咫尺
之内，颇具自然之趣。
LONG
	);
	set("exits", ([
		"northwest" : __DIR__"huafang",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -150);
	set("coor/y", 4080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
