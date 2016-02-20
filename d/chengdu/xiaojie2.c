// Room: /d/chengdu/xiaojie2.c
// Modifyed by Sir on Dec. 4 2001
// Last Modifyed by Winder on Dec. 24 2001

inherit ROOM;

void create()
{
	set("short", "小街");
	set("long", @LONG
这是一条青石板铺成的小街，路面非常干净。朝北边看，是一个酿
酒的小屋。东边是一座两层的楼阁，挂着“陈麻婆豆腐”的招帘，门额
上悬挂一方横匾“麻到为止”四字擦得闪闪发亮，乃是苏轼的手笔。阵
阵辣椒香味扑鼻而来,让你垂涎欲滴。
LONG	);
	set("outdoor","chengdu");
	set("exits", ([
		"west"      : __DIR__"gongqiao1",
		"southeast" : __DIR__"niangjiuwu",
		"northwest" : __DIR__"xiaojie1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8010);
	set("coor/y", -3030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

