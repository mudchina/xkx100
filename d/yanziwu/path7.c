// Room: /d/yanziwu/path7.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "碎石小径");
	set("long", @LONG
一条小路通往花圃深处。走在小路上，可以听到近处清溪水响。地
上碎石铺得很是齐整，看来是花了不少功夫了。北边就是红霞楼了。
LONG );
	set("outdoors", "mantuo");
	set("no_clean_up", 0);
	set("exits", ([
		"south"  : __DIR__"path6",
		"north"  : __DIR__"hongxia1",
	]));
	set("coor/x", 1250);
	set("coor/y", -1260);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}