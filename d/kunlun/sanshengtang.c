// Room: /d/kunlun/sanshengtang.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "三圣堂");
	set("long", @long
昆仑三圣堂乃“昆仑三圣”何足道所建，原为了修身养性，读书练
功。随着昆仑派日益壮大，名声远播，这里便成了昆仑派聚众议事，接
待各路江湖英雄的地方。“昆仑三圣”也只好另觅安静所在了。
long);
	set("exits",([
		"west"      : __DIR__"jiuqulang7",
		"east"      : __DIR__"jiuqulang3",
		"north"     : __DIR__"jiuqulang5",
		"south"     : __DIR__"jiuqulang1",
	]));
	set("objects",([
		CLASS_D("kunlun")+"/banshuxian" :   1,
		__DIR__"npc/kl-dizi1.c" :   1,
		__DIR__"npc/kl-dizi4.c" :   1,
	]));
	set("coor/x", -119990);
	set("coor/y", 40100);
	set("coor/z", 90);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping fam;
	fam = (mapping)me->query("family");
	if (dir == "north" &&
		objectp(present("ban shuxian", environment(me)) &&
		(!fam || fam["family_name"] != "昆仑派")) &&
		!me->query_temp("kl_pass"))
	{
		return notify_fail("班淑娴拦住你，说道：除非你能过得了我这一关，否则还是请另觅佳处。\n");
	}
	if (dir == "south" && me->query("kl_pass"))
		me->delete_temp("kl_pass");
	return ::valid_leave(me, dir);
}
