// Room: /d/lingxiao/didi.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "地底");
	set("long", @LONG 
这里按地势而言，早已深入地底，是这大雪山的山腹之中了。四周
土地潮湿，充满了一股浓浓的泥土味。墙上依然插着几支火把，照得四
周亮堂堂的。一个腰悬利剑，神情警惕的剑士，正守在一扇巨大的石门
（men）旁。
LONG );
	set("exits", ([
		"up" : __DIR__"laolang",
	]));
	set("objects", ([ 
		__DIR__"npc/shi" : 1,
	])); 
	set("item_desc", ([
		"men" : "一扇厚厚的石门,怕有千斤之重，使劲推推（push），不知道会不会开。\n"
	]) );
	set("coor/x", -30990);
	set("coor/y", -8900);
	set("coor/z", 120);
	setup(); 
}

void init()
{
	add_action("do_push", "push");
}
int do_push(string arg)
{
	object me=this_player();

	message_vision("$N气沉丹田，凝劲于腰，大喝一声，运劲向石门推去。\n",me);
	if (me->query("max_neili") < 500)
	{
		message_vision("$N累了个半死，石门却纹丝不动。\n",me);
		return 1;
	}
	message_vision("只听机关枢纽运做之声不绝，石门竟缓缓开了。\n",me);
	set("exits/enter",__DIR__"dilao");
	remove_call_out("close");
	call_out("close", 5, this_object());
	return 1;
}
void close_out()
{
	if (query("exits/enter")) delete("exits/enter");
}

void close(object room)
{
	message("vision","里面有人大喝一声：小王八蛋，你不进来，就给爷爷滚吧！话音刚落，一阵劲风击到，石门被砰地一下关了。\n", room);
	room->delete("exits/enter");
}

