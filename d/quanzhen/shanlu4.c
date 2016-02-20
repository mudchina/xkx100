// /d/quanzhen/shanlu4.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "道路");
        set("long", @LONG
此处位於终南山山脚。巍峨的终南山，自古以来就是历代名人游
览的圣地。它西起甘肃的岐山，东至陕西的潼关，其间跨越十馀县，
连绵八百馀里。素有万里终南山之称。往东可看见一座寺庙。往西是
一条通往密林的幽静小路。往北可上终南山.
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "northup" : __DIR__"shanlu8",
                "east"    : __DIR__"puguangsi",
                "west"    : __DIR__"shanlu5",
                "south"   : __DIR__"shanjiao",
        ]));

	set("coor/x", -3130);
	set("coor/y", 0);
	set("coor/z", 20);
	setup();
        replace_program(ROOM);
}
