// Room: /d/chengdu/shuchang.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "书场");
	set("long", @LONG
这里是全城有名的书场，每天来这里听书的络绎不绝，场场暴满，
要知道今天说啥，先看看这里墙上的海报。内容主要是些梁山泊、三国
演义等。也有不少武侠书可以看，有兴趣也可以一读。
LONG	);
	set("exits", ([
		"east" : __DIR__"nanjie2",
		"west" : __DIR__"shuoshuyuan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8060);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

