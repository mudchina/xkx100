// Room: /d/xingxiu/xiaojing.c
// Last Modified by winder on Apr. 25 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "小径");
	set("long", @LONG
这里是星宿海。因方圆几百里都是一望无际的湖泊和沼泽，当地牧
羊人称之为“海”。也因阴暗潮湿，毒虫繁殖甚富。星宿弟子常来此捕
捉毒虫，以备练毒之用。这里通向星宿海的深处。西面有一条小径，两
旁点缀了些花卉。虽是稀少，但在星宿海是一奇观了。不由得让人心花
怒放，哼起了小曲。
LONG
	);
	set("exits", ([
		"east" : __DIR__"xxh2",
		"west" : __DIR__"shidao",
	]));
	set("outdoors", "xingxiu");
	set("coor/x", -50100);
	set("coor/y", 20200);
	set("coor/z", 0);
	set("yushi_count", 1);
	setup();
}

void init()
{
	object obj, me = this_player();
	mapping fam;
	fam = (mapping)me->query("family");
  
	if(mapp(fam) && fam["family_name"] == "星宿派" &&
		me->query("xx_points") > 10 &&
		(random(30) == me->query("kar")) &&
		query("yushi_count") >= 1 &&
		!me->query_temp("yushi_get"))
	{
		write("你看见土里有个东西一"WHT"闪"NOR"，拣起来才发现原来是一小块玉石！\n");
		me->set_temp("yushi_get", 1);
		obj = new(__DIR__"obj/yushi");
		obj->move(me);
		add("yushi_count", -1);
	}
}

