// Room: /d/shaolin/shijie8.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "石阶");
	set("long", @LONG
这里看来是半山腰了。不远的前面有一座小石亭，几位游客
在这里歇息。山路到这里变得十分平坦，东边的山壁上题满了名
人即兴题下的诗句。远望山林间层峦迭嶂，满目滴翠。
LONG );
	set("exits", ([
		"westdown" : __DIR__"shanmen",
		"northup" : __DIR__"shijie9",
	]));
	set("no_clean_up", 0);
	set("outdoors", "shaolin");
	set("coor/x", 0);
	set("coor/y", 750);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}
