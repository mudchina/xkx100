// Room: /d/nanshaolin/dabeidian.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
	set("short", BLU"大悲殿"NOR);
	set("long", @LONG
大悲殿系取佛家大慈大悲之意，殿堂上四壁绘满了佛家十忍等大慈
大悲之事。系我佛弟子冥想领悟禅理增进佛法专有所在，地上摆着几个
蒲团，几本经卷，几个木鱼。几位僧人正在瞑目讼经，看来颇得禅悟。
LONG );
	set("exits", ([
		"west"  : __DIR__"xumidian",
		"east"  : __DIR__"qxdian",
		"north" : __DIR__"hguangc2",
		"south" : __DIR__"stoneroad1",
	]));
	set("objects",([
//		CLASS_D("shaolin") + "/dao-zheng" : 1,
		WEAPON_DIR+"hammer/muchui" : 1,
	]));
	set("book_count",1);
	set("coor/x", 1810);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
}

void init()
{
	this_player()->set_temp("mx_times", 10);
	add_action("do_mingxiang", "mingxiang");
}

int do_mingxiang()
{
	object ob, me = this_player();
	if ( me->query_temp("mx_times") == 0 )
	{
		message_vision("$N身子一滑从蒲团上跌了下去。\n", me);
		me->set_temp("mx_times", random(35));
		me->unconcious();
		return 1;
	}
	me->add_temp("mx_times", -1);	
	message_vision("$N虔诚地跪在蒲团上闭目冥思。\n", me);
	if ( random(30) == 15 && !present("xisui", me) &&
		query("book_count") >= 1)
	{
		add("book_count", -1);
		ob=new(__DIR__"obj/book-xisui");
		ob->move(this_object());
		tell_object(me, RED"你只觉心头一热，面前已多了一块血袍。\n"NOR);
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	if(me->query_temp("mx_times") >= 0 ) me->delete_temp("mx_times");
	return ::valid_leave(me, dir);
}

