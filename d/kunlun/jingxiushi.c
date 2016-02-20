// Room: /d/kunlun/jingxiushi.c
// Last Modified by winder on Nov. 14 2000

inherit ROOM;

void create()
{
	set("short", "静修室");
	set("long", @LONG
这里是静修室，地下顺序地放着几个蒲团，正中烧着几柱香，轻烟
袅袅升起。几位昆仑派弟子正盘膝坐在上面打坐静修。
LONG );
	set("exits", ([
		"east"  : __DIR__"huayuan1",
	]));
	set("objects", ([
		"/d/village/obj/zhujian" : 2,
	]));
	set("no_fight", 1);
	set("no_clean_up", 0);
	set("coor/x", -120000);
	set("coor/y", 40080);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}