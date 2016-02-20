// Room: /d/nanshaolin/cjlou1.c
// Last Modified by winder on May. 29 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "藏经阁二楼");
	set("long", @LONG
千余年来少林寺执中原武林之牛耳，自达摩老祖以下，历代人材辈
出。其中有不少高僧遗著留存，汇集至今，终成名震天下的少林七十二
绝艺。福建下院转抄本院典籍，是故，少林精华，尽集于此。二楼四面
开窗，确保通风。中间排列着五排大书架。四周则陈列矮几，以供阅读。
几位老僧手执经卷，正在闭目凝思。
LONG );
	set("exits", ([
		"down" : __DIR__"cjlou",
	]));
	set("objects",([
		CLASS_D("nanshaolin") + "/fangge" : 1,
		BOOK_DIR+"nwuji1" : 1,
		BOOK_DIR+"nwuji2" : 1,
		BOOK_DIR+"nwuji3" : 1,
	]));
	set("coor/x", 1890);
	set("coor/y", -6150);
	set("coor/z", 30);
	setup();
}

int valid_leave(object me, string dir)
{
	object *ob;
	int i;

	if ( present("fang ge", environment(me)) && dir == "down")
	{
		ob = deep_inventory(me);
		i = sizeof(ob);
		while (i--)
			if (ob[i]->id("shaolin wuji"))
				return notify_fail("方戈说道: 武功秘籍只许在藏经阁内研习，不得携带外出！\n");
	}
	return ::valid_leave(me, dir);
}
void init()
{
	add_action("do_jump", ({ "jump", "tiao" }));
	add_action("do_tui", ({ "tui", "push" }));
} 
int do_jump(string arg)
{
	object me;
	me = this_player(); 
	if (arg != "chuang" ) return 0;
	if ( !arg ) return 0;
	if (!me->query_temp("marks/推")) return notify_fail("你要做什么？\n");

	if( (int)me->query_skill("dodge",1) < 120 )
	{
		message_vision( HIR"$N推开窗户，纵身跃起直奔窗外，无奈轻功不够，没有跳过窗台，就摔了下来！\n"NOR, me);
		me->unconcious();
		return 1;     
	}  
	message_vision("$N推开窗户,纵身跃出窗户，一眨眼就不见了 。\n", me);
	me->move(__DIR__"xiaoxi");
	tell_room(environment(me), me->name() + "从藏经阁飞身跃了过来。\n", ({ me }));
	me->delete_temp("marks/推");
     	return 1;
}
int do_tui(string arg)
{
	if( !arg || arg == "" || arg !=  "chuang") return 0;
	write("你轻轻的将藏经阁的窗户推开。\n");
	this_player()->set_temp("marks/推", 1);
	return 1;
}
