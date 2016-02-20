// Room: /d/quanzhou/dudufu.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "都督府");
	set("long", @LONG
这是泉州都督的府邸。泉州都督掌管泉州的海陆兵权，控制着西洋
广大海域，管辖当世最强大的远洋水师，乃一等一重要的官职。
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"west"  : __DIR__"duduxiang",
		"south" : __DIR__"micangxiang",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 1870);
	set("coor/y", -6500);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "south" && objectp(present("wu jiang", environment(me))))
		return notify_fail("武将大喝道：都督有令，闲杂人等不能由此经过！\n");
	return ::valid_leave(me, dir);
}

