// Room: /d/hengshan/cuipinggu1.c
// Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short", "翠屏谷");
	set("long", @LONG
浑河在谷中冲刷而过，天峰岭和翠屏山分列峡谷两侧，绝壁千仞，
犹如刀削斧劈，高耸入云，这里自古就是塞外通往内地的咽喉要道，真
有一夫当关万夫莫开之势。
LONG
	);
	set("exits", ([
		"southeast"  : __DIR__"cuipinggu2",
		"northwest"  : __DIR__"jinlongxia",
	]));
	set("objects", ([
		CLASS_D("hengshan")+"/wen" : 1,
	]));
	set("outdoors", "hengshan");
//	set("no_clean_up", 0);
	set("coor/x", -10);
	set("coor/y", 3190);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

