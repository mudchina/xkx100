// Room: /binghuo/wangpanlin.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
王盘山是个小岛，山石树木亦无可观之处。东南角有个港湾，桅
樯高耸，停泊着十来艘大船，想是巨鲸帮、海沙派一干人的座船。林
里两个剑客正在比剑，招数巧妙狠辣，原来两人并非练习剑法，竟是
真打真斗。
LONG );
	set("no_sleep_room",1);
	set("outdoors", "wangpan");
	set("exits", ([
		"southeast" : __DIR__"wangpangang",
		"southwest" : __DIR__"wangpangu2",
		"west"      : __DIR__"wangpanshan",
	]));
	set("objects", ([
		__DIR__"npc/gao" : 1,
		__DIR__"npc/jiang" : 1,
	]));
	setup();
	replace_program(ROOM);
}

