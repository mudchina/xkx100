// Room: /city/hangou0.c
// Last Modified by winder on Apr. 10 2000

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "古邗沟边");
	set("long", @LONG
古邗沟最后是要汇入南北大运河的，这一段的大运河称为真楚运河。
古邗沟就是在此汇入真楚运河的。由于靠近河口，这里的交通更加繁忙，
而在岸上，这里的村庄也格外的稠密，常有村民驾小舟出没于大船之间，
其技术不能不让人赞叹。 
LONG );
	set("exits", ([
		"west" : __DIR__"hangou1",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

