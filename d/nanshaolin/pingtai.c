// Room: /d/nanshaolin/pingtai.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "平台");
	set("long", @LONG
这里是大雄宝殿前的一处平台，乃是全寺的中心点，寺中的重大活
动多在此举行。东面是紧那罗王殿，西面是六祖殿。
LONG );
	set("exits", ([
		"north"     : __DIR__"daxiong",
		"east"      : __DIR__"jnlwang",
		"west"      : __DIR__"liuzu",
		"southdown" : __DIR__"dxshijie",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/daku" : 1,
	]));
	set("valid_startroom",1);
	set("outdoors", "nanshaolin");
	set("coor/x", 1820);
	set("coor/y", -6210);
	set("coor/z", 20);
	setup();
	"/clone/board/nshaolin_b"->foo();
}

