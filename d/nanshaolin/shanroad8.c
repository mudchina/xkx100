// Room: /d/nanshaolin/shanroad8.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是南少林后门外的一条小路，路旁长满的青草。黄土铺就的小路
看起来很齐整，似乎有人经常打扫。前面就是后山，山势挺拔，景秀境
幽，峰上种满了松树，随着微风拂过，传来阵阵滔声。东面是一片松林，
林外竖着一块木牌(mupai)。
LONG );
	set("exits", ([
		"east"      : __DIR__"shulin1",
		"southwest" : __DIR__"shanroad7",
        ]));
        set("item_desc",([
		"mupai"	:   "少林寺护法松林，违令擅入者杀无赦！\n",
	]));
	set("no_clean_up", 0);
	set("outdoors", "nanshaolin");
	set("coor/x", 1830);
	set("coor/y", -6010);
	set("coor/z", 50);
	setup();
        replace_program(ROOM);
}

