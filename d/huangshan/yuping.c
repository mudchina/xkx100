// Room: /d/huangshan/yuping.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "玉屏楼");
	set("long", @LONG
这群高大的建筑，因为背靠玉屏峰，所以又称玉屏楼。在此可以尽
收玉屏，莲花两峰秀色。东观天都，从山顶直落山脚，近乎垂直，西看
莲花，恰似“突兀撑青穹”的盛开芙蓉。玉屏峰地处三大主峰中心，集
黄山奇景大成，“四海”烟云气吞山河，“三奇”美景叠现不穷。又称
“黄山绝胜处”。
LONG
	);
	set("exits", ([ 
		"north"     : __DIR__"lianhua",
		"southeast" : __DIR__"yingke",
		"southwest" : __DIR__"lianrui",
	]));
	set("no_clean_up", 0);
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
