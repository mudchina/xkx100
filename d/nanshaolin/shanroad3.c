// Room: /d/nanshaolin/shanroad3.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
这是南少林后门外的一条小路，路旁长满的青草。黄土铺就的小路
看起来很齐整，似乎有人经常打扫。前方少林后山，山势挺拔，景秀境
幽，峰上种满了松树，随着微风拂过，传来阵阵滔声。
LONG );
	set("exits", ([
		"north"     : __DIR__"shanroad4",
		"southdown" : __DIR__"shanroad2",
	]));
	set("outdoors", "nanshaolin");
	set("no_clean_up", 0);
	set("coor/x", 1820);
	set("coor/y", -6060);
	set("coor/z", 30);
	setup();
        replace_program(ROOM);
}

