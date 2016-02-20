// Room: /d/xiakedao/xkroad4.c
// Modified by Java on Feb.14.1998
inherit ROOM;

void create()
{
	set("short", "南海渔村");
	set("long", @LONG
这是南海沿岸的偏僻小村，稀稀落落的几户人家。空地上晾着几
顶渔网。南面就是波涛浩淼的南海了。向西走好象还有个渔港。东面
是小村的沙滩晒网场。
LONG );
        set("outdoors", "xiakedao");
	set("exits", ([
		"north"   : __DIR__"xkroad3",
		"east"    : __DIR__"xkroad5",
		"west"    : __DIR__"haigang",
	]));
        set("no_clean_up", 0);
	set("coor/x", -1400);
	set("coor/y", -9000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}