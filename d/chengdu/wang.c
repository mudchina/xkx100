// Room: /d/chengdu/wang.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "梁王府");
	set("long", @LONG
这里是梁王府的大门，两边是两个威武的石狮子，高高的台阶，中
间是正门，两边是边门，几个王府卫士整齐的守卫在两旁，门口显得很
安静，普通百姓是不许逗留的。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east" : __DIR__"nanjie1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8060);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

