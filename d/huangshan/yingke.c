// Room: /d/huangshan/yingke.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "迎客松");
	set("long", @LONG
从半山寺过来，一过蓬莱三岛，远远便可以看见一株古松伸出“双
臂”，宛若主迎远客。松高十余米，树冠茂密，过了迎客松，标志着人
们已经踏入“万山拜其下，孤云卧此中”的文殊院了。
LONG
	);
	set("exits", ([ 
		"southdown" : __DIR__"guanyin",
		"northwest" : __DIR__"yuping",
		"northeast" : __DIR__"wenzhu",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
