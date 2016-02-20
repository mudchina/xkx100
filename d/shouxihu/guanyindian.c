// Room: /yangzhou/guanyindian.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "观音殿");
	set("long", @LONG
观音殿俗称小南海，面西三楹。殿内供奉六尊白玉雕像，为明代雕
刻瑶台女神。殿外庭院，两株百年古柏参天而立。殿前六角吹花门，通
“寒竹风松”半亭。出殿南方门“香海慈云”，沿石级而下，可达“湖
上草堂”。
LONG );
	set("exits", ([
		"west"      : __DIR__"banting",
		"southdown" : __DIR__"caotang",
		"eastup"    : __DIR__"pingtai1",
	]));
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 120);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}