// Room: /city/chanzhidadian.c

inherit ROOM;

void create()
{
	set("short", "禅智寺大殿");
	set("long", @LONG
正中修的是如来佛祖的金身塑像，两边列了十八罗汉。庙虽然不算
是大，但菩萨供得如此之全，倒也是少见，可以看出扬州一带的富裕程
度了。殿上香火缭绕，诵经之声不绝于耳。
LONG );
	set("exits", ([
		"east"   : __DIR__"chanzhixf",
		"south"  : __DIR__"chanzhisi",
	]));
	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", -8);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}