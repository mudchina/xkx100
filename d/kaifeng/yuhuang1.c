// /kaifeng/yuhuang1.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "玉皇阁");
	set("long", @LONG
玉皇阁高十三米坐北朝南，采用仿木结构均用砖砌成。外观下阁上
亭。下圆下方，造型奇特，是一座集蒙古包与阁楼巧妙结合，具有元代
风格的建筑。阁内供有真武铜像一尊。
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"up"    : __DIR__"yuhuang2",
		"south" : __DIR__"sanqing",
	]));

	setup();
	replace_program(ROOM);
}
