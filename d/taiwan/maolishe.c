// Room: /d/taiwan/maolishe.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "猫里社");
	set("long", @LONG
猫里社位于竹堑西南。清朝初年，此地的汉人还很少，居住在这里
的主要是泰雅族人，他们以渔猎为生。
LONG );
	set("exits", ([
		"eastup"    : __DIR__"dabajianshan",
		"northeast" : __DIR__"zhuqian",
		"southwest" : __DIR__"banxianshe",
	]));
	set("objects", ([
		__DIR__"npc/taiyaren": 1,
	]));

	set("outdoors", "taiwan");
	set("coor/x", 2520);
	set("coor/y", -6990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

