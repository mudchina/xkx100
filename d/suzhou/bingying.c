// Room: /d/suzhou/bingying.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "兵营");
	set("long", @LONG
这里是兵营，密密麻麻到处都是官兵，有的在武将的指挥下列队操
练，有的独自在练功，有的坐着、躺着正在休息。南墙下坐着主帅，不
动声色地寻视着四周。看到你进来，他们全都向你包围了过来，形势看
来不太妙。
LONG );
	set("outdoors", "suzhou");
	set("exits", ([
		"north"  : __DIR__"bingyinggate",
	]));
	set("objects", ([
		"/d/city/npc/wujiang": 1,
		"/d/city/npc/bing": 4,
	]));
	set("coor/x", 840);
	set("coor/y", -1030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
