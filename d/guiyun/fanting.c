// Room: /d/guiyun/fanting.c
// Last Modified by winder on Jul. 9 2001

#include <ansi.h>
inherit ROOM;

int do_sit(string arg);
int do_stand();
void delete_served(object me);

void create()
{
	set("short", "饭厅");
	set("long", @LONG
这是归云庄弟子们每日吃饭的地方，饭菜的香味充溢着整个房间。
屋里摆着一张大桌子(table)和一些椅子(chair)。屋中站着几个仆役。
LONG
	);
	set("exits", ([
		"east"  : __DIR__"chufang",
		"west"  : __DIR__"chafang",
		"north" : __DIR__"lianwuchang",
	]));
	set("item_desc", ([
		"table" : "一张大八仙桌，上面放着一些碗、盘、筷、勺等器具。\n",
		"chair" : "竹制的坐椅，看上去有些摇摇晃晃。\n",
	]));
	set("no_fight", 1);
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
	message_vision("仆役走过来，给$N端来了一碗米饭。\n", me);
	
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
	mixed *local;

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");
	if (arg == "table" || arg == "zhuozi")
		return notify_fail("你要坐在桌子上？那先把你煮熟了再端上来吧。\n");	

	if ( !arg || (arg != "chair" && arg != "yizi") )
		return notify_fail("你要坐在地板上？有个性！可惜的是这会影响归云庄的形象。\n");	
	if (me->query_temp("marks/sit"))
		return notify_fail("你已经坐在座位上了。\n");	
	message_vision("$N找了个空位座下，等着吃饭。\n", me);	
	local = localtime(time() * 60);
	if (local[2] < 6) {
		message_vision("仆役走过来对$N说：大半夜的您让小的去哪里弄吃的啊？\n", me);
		message_vision("$N无奈地又站了起来。\n", me);	
		return notify_fail("");
	}
	else if (local[2] > 8 && local[2] < 11) {
		message_vision("仆役走过来对$N说：过了早饭时间啦，中午再来吧。\n", me);
		message_vision("$N无奈地又站了起来。\n", me);	
		return notify_fail("");
	}
	else if (local[2] > 13 && local[2] < 17) {
		message_vision("仆役走过来对$N说：过了午饭时间啦，晚上再来吧。\n", me);
		message_vision("$N无奈地又站了起来。\n", me);	
		return notify_fail("");
	}
	else if (local[2] > 20) {
		message_vision("仆役走过来对$N说：过了晚饭时间啦，您就忍一宿吧。\n", me);
		message_vision("$N无奈地又站了起来。\n", me);	
		return notify_fail("");
	}
	if( me->query_temp("marks/food_served") ) {
		message_vision("仆役走过来对$N说：吃饱了的就出去吧，别占着地方！\n", me);
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
		return notify_fail("仆役跑过来说：没吃完的也别带走啊，考虑一下别人嘛。\n");
	
	return ::valid_leave(me, dir);
}
