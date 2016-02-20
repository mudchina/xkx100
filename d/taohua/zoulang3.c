// Room: /d/taohua/zoulang3.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
一条连接大厅和练武场的回廊。走廊外花木扶疏，桃花满地，远处
碧蓝色的大海和翠绿的岛屿映衬着点点白帆，历历如画。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("exits", ([
		"west" : __DIR__"lianwuchang",
		"east" : __DIR__"zoulang1",
		"north": __DIR__"daojufang",
		"south": __DIR__"bingqi",
	]) );

	set("coor/x", 8990);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir != "east" && me->query("family/family_name") != "桃花岛")
		return notify_fail("一位哑仆拦住了你，用手势比划着表示那边不能去。\n");
	
	return ::valid_leave(me, dir);
}