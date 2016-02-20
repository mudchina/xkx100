// Room: /d/foshan/nanling.c 南岭山口
// Modified by Java on Feb.14.1998
inherit ROOM;

void create()
{
	set("short", "南岭山口");
	set("long", @LONG
这里是南岭的一个山口。南面就是佛山了，北面是横亘湖南广
东的五岭。这里地气炎热，百物速生快长，口音也远异中原了。
LONG );
	set("outdoors", "foshan");
	set("exits", ([
		"northup" : "/d/henshan/hsroad9",
		"south"   : __DIR__"northgate",
	]));
        set("no_clean_up", 0);
	set("coor/x", -1400);
	set("coor/y", 5000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
