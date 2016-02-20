// Room: /d/baituo/shijie.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","石阶");
	set("long",@TEXT
你走在青石板铺成的石阶上。这里就是传说中神秘的白驼山。远远
望去，两座白沙堆积形成的山峰好像一只骆驼的脊背。一座山门立在你
的眼前。
TEXT );
	set("exits",([
		"east"      : __DIR__"caoping",
		"northup"   : __DIR__"damen",
		"southdown" : __DIR__"guangchang" ,
	]));
	set("outdoors", "baituo");
	set("no_clean_up", 0);
	set("coor/x", -50010);
	set("coor/y", 20000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
