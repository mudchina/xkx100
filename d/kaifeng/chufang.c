// /kaifeng/chufang.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "素斋厅");
	set("long", @LONG
这是寺庙中的大小僧人用餐的地方，当然方丈的素斋是专门有人送
过去的，平时相国寺的僧人听钟吃饭，等他们吃完了也经常把剩下的素
斋舍给穷人吃。逢塑望，十五也经常作些斋席请大施主，高官富贵们品
尝，所以素斋厨的僧人是最忙的。
LONG
	);
	set("exits", ([
		"north" : __DIR__"chufang2",
		"west" : __DIR__"zhongyuan",
	]));
	set("objects", ([
		__DIR__"npc/liucaizhu" : 1,
		__DIR__"npc/kong" : 1,
	]));

	setup();
	replace_program(ROOM);
}
