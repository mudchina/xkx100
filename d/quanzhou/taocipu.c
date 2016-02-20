// Room: /d/quanzhou/taocipu.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "陶瓷铺");
	set("long", @LONG
这里烧制各式各样的陶瓷制品。柜台上摆着花色各异的碗碟瓶罐，
白皙透明，巧夺天工。动物瓷器，细腻圆润，栩栩如生。由于它的特殊
地位，因此生意和技术从来都是传子不传女。
LONG );
	set("no_clean_up", 0);
	set("exits", ([
		"north"   : __DIR__"xinmenji",
	]));
	set("coor/x", 1840);
	set("coor/y", -6590);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
