// Room: /d/taohua/zoulang4.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
一条连接大厅和书房的回廊。走廊外花木扶疏，桃花满地，远处碧
蓝色的大海和翠绿的岛屿映衬着点点白帆，历历如画。
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("exits", ([
		"west" : __DIR__"dating",
		"east" : __DIR__"bookroom",
		"north": __DIR__"tanzhige",
		"south": __DIR__"pikonglang",
	]) );

	set("coor/x", 9020);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "桃花岛") && dir != "west")
		return notify_fail("一位哑仆拦住了你，用手势比划着表示那边不能去。\n");

	return ::valid_leave(me, dir);
}