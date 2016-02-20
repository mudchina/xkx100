// qianting.c 前厅
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "前厅");
	set("long", @LONG
这里是古墓的前厅，黑黝黝的，你几乎什么也看不清。全靠大厅
正中间的梁上悬挂着一颗夜明珠，映射出淡淡的黄光。厅柱都是由硕
大的石柱砌成的，上面似乎还写着一些什么字(zi)，昏暗中似是重阳
手笔。可你不仔细看怎么也看不清楚。
LONG	);
	set("item_desc", ([
		"zi": "秋水为神玉为骨    芙蓉如面柳如眉\n"
	]));
	set("exits", ([
		"west"  : __DIR__"mudao02",
		"east"  : __DIR__"mudao05",
		"south" : __DIR__"mudao04",
		"north" : __DIR__"mudao01",
	]));
	set("objects", ([
		CLASS_D("gumu")+"/first" : 1,
	]));
	set("coor/x", -3220);
	set("coor/y", 10);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
