// Room: /yangzhou/gulintang.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short","谷林堂");
	set("long",@LONG
苏东坡徙知扬州，为纪念恩师欧阳修而建谷林堂。取其诗句“深谷
下窈窕，高林合扶疏”中“谷林”二字为堂名。“谷林堂”匾，为方颐
题书。
谊。
LONG );
	set("exits", ([
		"east"  : __DIR__"daxiongbaodian",
		"south" : __DIR__"pingshantang",
		"north" : __DIR__"ouyangci",
	]));
	set("no_clean_up", 0);
	set("coor/x", -40);
	set("coor/y", 170);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}