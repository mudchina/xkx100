// Room: /d/kunlun/qianting.c
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "前厅");
	set("long",@long
这里是座大厅，高檐大瓦，十分的简朴而壮阔，厅内摆几张高背方
椅，一张八仙桌，看来是接待客人的地方，西面和东面也是客厅，供客
人歇息，北面一条长廊通向后面。
long);
	set("exits",([
		"south" : __DIR__"pingfeng",
		"north" : __DIR__"shilu1",
		"west"  : __DIR__"wlang01",
		"east"  : __DIR__"elang01",
	]));
	set("objects",([
		CLASS_D("kunlun")+"/xihuazi" : 1,
	]));
	set("valid_startroom", 1);
	set("coor/x", -119990);
	set("coor/y", 40060);
	set("coor/z", 90);
	setup();
	"/clone/board/kunlun_b"->foo();
}

int valid_leave(object me, string dir)
{
	mapping fam;
	fam = (mapping)me->query("family");

	if ((!fam || fam["family_name"] != "昆仑派") && dir == "north" &&
		objectp(present("xi huazi", environment(me))))
		return notify_fail("西华子拦住你，说道：这里是昆仑派的地盘，不要随意乱闯！\n");

	return ::valid_leave(me, dir);
}