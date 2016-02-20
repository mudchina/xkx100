// Room: /d/nanshaolin/zhlou6.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "钟楼六层");
	set("long", @LONG
沿窗洞吹进一阵阵凌厉的山风，寒意浸人。北望可见松林的尽头，
头顶上的楼板开了个大洞，挂下一口大钟。从这里只能看到巨钟的下边
缘，内里黑洞洞的，什么也看不见。
LONG );
	set("exits", ([
		"up"   : __DIR__"zhlou7",
		"down" : __DIR__"zhlou5",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1840);
	set("coor/y", -6280);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}

