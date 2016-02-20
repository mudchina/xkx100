// Room: /d/taohua/fanting1.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;
int do_sit(string arg);
int do_stand();
void delete_served(object me);

void create()
{
	set("short", "饭厅");
	set("long", @LONG
这是桃花岛弟子们每日吃饭的地方，饭菜的香味充溢着整个房间。
屋里摆着一张大桌子(table)和一些椅子(chair)。屋中站着几个哑仆。
LONG
	);

	set("exits", ([
		"north" : __DIR__"chufang1",
		"west" : __DIR__"chafang1",
		"east" : __DIR__"lianwuchang",
	]));
	
	set("item_desc", ([
		"table" : "一张大八仙桌，上面放着一些碗、盘、筷、勺等器具。\n",
		"chair" : "竹制的坐椅，看上去有些摇摇晃晃。\n",
	]));
	                                

	set("no_fight", 1);
	
	set("coor/x", 8970);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_stand", "stand");
	add_action("do_stand", "zhan");
	add_action("do_sit", "sit");
	add_action("do_sit", "zuo");
}

int serve_food(object me)
{
	if (!present(me, this_object())) return 0;
	message_vision("哑仆走过来，给$N端来了一碗米饭。\n", me);
	
	new(__DIR__"obj/mifan")->move(me);

	me->set_temp("marks/food_served", 1);
	call_out("delete_served", 120, me);
	return 1;
}

void delete_served(object me)
{
	if ( objectp(me) ) me->delete_temp("marks/food_served");
}

int do_sit(string arg)
{
	object me = this_player();
	string time = NATURE_D->game_time();

	if(me->is_busy() || me->is_fighting()) return notify_fail("你正忙着呢！\n");
	if(arg == "table" || arg == "zhuozi")
		return notify_fail("你要坐在桌子上？那先把你煮熟了再端上来吧。\n");	
	if( !arg || (arg != "chair" && arg != "yizi") )
		return notify_fail("你要坐在地板上？有个性！可惜的是这会影响桃花岛的形象。\n");	
	if (me->query_temp("marks/sit"))
		return notify_fail("你已经坐在座位上了。\n");	
	message_vision("$N找了个空位座下，等着吃饭。\n", me);	
	if( (strsrch(time, "辰时") == 0) && (strsrch(time, "午时") == 0) && (strsrch(time, "酉时") == 0) ) 
	{
		message_vision("哑仆走过来对$N打手势，表示现在不是吃饭时间。\n", me);
		message_vision("$N无奈地又站了起来。\n", me);	
		return notify_fail("");
	}
	if( me->query_temp("marks/food_served") )
	{
		message_vision("哑仆走过来对$N打手势，表示吃饱了的就不要再吃了。\n",me);
		message_vision("$N发觉众人的眼光都在盯着自己，忙站起身来，尴尬地说：我只是试试这椅子结实不结实。\n", me);
		return notify_fail("");
	}
	me->set_temp("marks/sit", 1);
	call_out("serve_food", 1, me);
	return 1;
}

int do_stand()
{
	object me = this_player();

	if (!me->query_temp("marks/sit"))
		return notify_fail("你已经站着了，是不是站久了有点发昏啊？\n");	
	message_vision("$N拍拍屁股，站了起来。\n", me);	
	me->delete_temp("marks/sit");
	return 1;
}

int valid_leave(object me, string dir)
{
	if (me->query_temp("marks/sit"))
		return notify_fail("你打算连椅子也搬出去？\n");	
	if ((dir == "north") && present("dami fan", me))
//	if (random(3)) 
		return notify_fail("哑仆跑过来打手势，表示不能把没吃完的带走。\n");
	return ::valid_leave(me, dir);
}
