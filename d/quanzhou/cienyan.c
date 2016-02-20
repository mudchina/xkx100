// Room: /d/quanzhou/cienyan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "赐恩岩");
	set("long", @LONG
这里巨石绵绵，相连成片。寺宇成排，有佛殿、功德堂、许氏宗祠
等。巨石群中有两块大岩石昂然伸出，使底下形成一个天然石室，上刻
「高山仰止」。据称是唐中叶泉州的进士与韩愈、陆贽等同登「龙虎榜
」的欧阳詹的读书的书室。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southdown" : __DIR__"shanlu5",
		"northdown" : __DIR__"shanlu4",
	]));
	set("coor/x", 1850);
	set("coor/y", -6460);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
