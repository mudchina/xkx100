// Room: /d/taishan/sihuaishu.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "四槐树");
	set("long", @LONG
柏洞北面出去，有古槐株，高大擎云，蔚然葱翠，传为唐槐，其地
名就叫四槐树。后来光阴荏苒，日月穿梭，又衍生了三株槐树，地名便
不再改。
LONG );
	set("exits", ([
		"northup"   : __DIR__"hutiange",
		"southdown" : __DIR__"baidong",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 400);
	set("coor/y", 640);
	set("coor/z", 70);
	setup();
	replace_program(ROOM);
}
