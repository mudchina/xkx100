// Room: /d/huanggong/qinghedian.c
inherit ROOM;

void create()
{
	set("short", "清和殿");
	set("long", @LONG
清和殿, 这是康熙爷与纳兰皇后用膳的地方. 皇后不喜欢吵闹, 
所以你们不得大声说话. 长长的檀香桌上已为圣上准备好了一席满汉
全席. 真香啊!
LONG
	);

	set("exits", ([
		"east" : __DIR__"yushanfang",
	]));
	set("objects", ([
		__DIR__"obj/nverhong" : 2,
		__DIR__"npc/taijian" :1,
	]));

	set("coor/x", -190);
	set("coor/y", 5260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}