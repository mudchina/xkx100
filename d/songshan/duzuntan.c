// Room: /d/songshan/duzuntan.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;

void create()
{
	set("short", "独尊坛");
	set("long", @LONG
这里是独尊坛。向来五岳以泰山号称“独尊”，但自从十来年前嵩
山派夺得五岳盟主一席后，江湖上五岳独尊的地位就是嵩山的了。这里
陈列华贵，雕梁画栋，也着实花了不少心力。
LONG );
	set("exits", ([
		"south" : __DIR__"houting",
	]));
	set("objects", ([
		CLASS_D("songshan")+"/deng": 1,
	]));
	set("coor/x", -20);
	set("coor/y", 940);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}
