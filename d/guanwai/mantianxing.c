// /guanwai/mantianxing.c

inherit ROOM;

void create()
{
	set("short", "满天星");
	set("long", @LONG
这里是一片开阔的平原，附近不但没有任何小山丘陵，就连一棵树
也找不到。抬眼望去，地平线笔直的将蓝天与雪原分隔在两边。据说夜
间因这里无物遮挡，可遍观满天星斗。进山的人们多在此祈求上苍的保
佑。
LONG );
	set("exits", ([
		"southeast" : __DIR__"caoguduo",
		"west"      : __DIR__"ermenkan",
	]));
	set("no_clean_up", 0);
	set("outdoors", "guanwai");
	set("coor/x", 6120);
	set("coor/y", 5220);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}