// Room: /d/yueyang/jiuxiangshan.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "酒香山");
	set("long", @LONG
传说山上有美酒，喝了能成仙。想长生不老的汉武帝听说后，便派
文士栾巴到君山求酒。酒求回后，便被东方朔给抢先喝了，后来闹出一
场笑话。大抵是汉武帝大怒，欲斩东方朔。东方朔辩称，如自己被赐而
死，则仙酒无长生功效，自然不是真仙酒；仙酒既然不真则朔不当死。
汉武帝两难之间，无法可施。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"jiuxiangting",
		"west"  : __DIR__"yangyaozai",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/bai-shijing" : 1,
	]));
	set("coor/x", -1780);
	set("coor/y", 2290);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
