// Room: /d/jiaxing/njroad5.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "村中小路");
	set("long", @LONG
一条村中的小路。南边就是钱塘江了，那边的树下聚集着一些闲散
的村民。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","jiaxing");

	set("exits", ([
		"north": __DIR__"njroad4",
		"south": __DIR__"jiangpan1",
	]) );

	set("coor/x", 1580);
	set("coor/y", -1070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}