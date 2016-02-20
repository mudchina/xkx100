// Room: /d/huangshan/huangshan.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	object con,item;
	set("short", "黄山剑庐");
	set("long", @LONG
好不容易过铁索，眼前一亮，居然有间茅屋，屋上居然也有牌匾上
书“黄山剑庐”，屋内陈设简单，一张红木桌上放着几册经卷，笔筒中
稀疏地插着几只狼毫，西墙一柄长剑，上书“苍穹”二字。
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"tiesuo",
	]));
	set("no_clean_up", 0);
	setup();
}
init()
{
	add_action("do_climb","climb");
}
int do_climb(string arg)
{
	object 	me;
	int mlvl;

	if(!arg || arg != "down")
	{
		write("你要往哪里爬？\n");
		return 1;
	}
	me = this_player();
	message_vision( "\n$N慢慢地向下爬去。\n" , me);
	me->start_busy(4);
	call_out("fliping",4,me);
	me->stop_busy();
	return 1;
}

int fliping(object me)
{
	if( !me->is_ghost())
	{
		me->move(__DIR__"kuzhu");
		message_vision("$N顺着崖壁爬了下来。\n", me);
	}
	return 1;
}
