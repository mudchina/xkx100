// Room: /d/huijiang/xiepo.c
// Last Modified by winder on Sep. 12 2001
inherit ROOM;

void create()
{
	set ("short", "斜坡");
	set ("long", @LONG
两边的树林稀稀落落的，在西北边塞的寒风吹动中发出沙沙的响声。
北面的草原上牛羊在吃草，放羊的姑娘轻轻的挥着鞭子，南面的树林中
有几个帐篷，透出一股杀气。
LONG);
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 2 */
		"northdown" : __DIR__"caoyuan",
		"southup"   : __DIR__"buluo2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50050);
	set("coor/y", 9070);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
