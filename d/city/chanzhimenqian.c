// Room: /city/chanzhimenqian.c

inherit ROOM;

void create()
{
	set("short", "禅智寺门前");
	set("long", @LONG
这里是禅智寺门前的一块空地，两边是寺庙里种的芍药圃，现在正
值芍药开放之时，远远就能看到火红的一片，东边新搭起一座赏芍药的
花棚。向北可以看到寺庙高高的殿门，东南边是草河南街。
LONG );
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast"  : __DIR__"caohenanjie",
		"north"      : __DIR__"chanzhisi",
		"east"       : __DIR__"huapeng",
		"west"       : __DIR__"shaoyaopu",
	]));
	set("coor/x", -20);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}