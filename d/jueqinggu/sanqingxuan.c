// Room: /d/jueqinggu/sanqingxuan.c
// Last Modified by winder on Feb. 17 2001

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "三清轩");
	set("long", @LONG
这里是绝情谷谷主会客的地方，轩内墙壁上挂了许多书法图画，门
窗皆浮雕纹饰，四周是回廊。
LONG
	);

	set("exits", ([
		"north"    : __DIR__"shufang",
		"eastdown" : __DIR__"songtang",
		"south"    : __DIR__"jiantan",
		"southwest": __DIR__"huilang1",
	]));
	set("objects", ([
		__DIR__"npc/gongsunzhi" : 1,
	]));
	set("coor/x", -540);
	set("coor/y", -360);
	set("coor/z", 20);
	setup();
 
}
int valid_leave(object me, string dir)
{
	if (!me->query("jqg_pass") &&
		present("gongsun zhi", environment(me)) &&
		(dir =="south" || dir =="north" || dir=="southeast"))
		return notify_fail("公孙止怒斥到，你以为你是小龙女啊，在我绝情谷里乱跑？！\n");
	return ::valid_leave(me, dir);
}
