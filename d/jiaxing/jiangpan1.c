// Room: /d/jiaxing/jiangpan1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "江畔");
	set("long", @LONG
一条大江横亘在面前，江水浩浩，日日夜夜无穷无休地奔向大海。
这里有一排乌柏树，叶子似火烧般红。两棵大松树下正围着一堆村民，
聚精会神地听着一个瘦削的老者说话。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","jiaxing");

	set("exits", ([
		"north":     __DIR__"njroad5",
		"southeast": __DIR__"jiangpan2",
	]) );

	set("coor/x", 1580);
	set("coor/y", -1080);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}