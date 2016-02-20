// door.c

inherit ITEM;
void dest();
void setup()
{}

void init()
{
	add_action("do_enter", "enter");
	add_action("do_enter", "knock");
	add_action("do_enter", "break");
	call_out("dest", 50);
}

void create()
{
	set_name("暗门", ({"door",}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一个很小的暗门。\n");
		set("unit", "个");
		set("material", "wood");
		set("no_get", "穷疯啦，门也要？\n");
	}
	setup();
}


int do_enter(string arg)
{
	object me;
	int i,ging_cost, qi_cost;
	me = this_player();

	if( !arg || arg=="" ) return 0;
	if (me->query_temp("doorisok") ) 
	{
		me->delete_temp("doorisok"); 
		message("vision","现在可以往北走.\n",environment(me));
		return 1;
	}
	if( arg=="door" ) 
	{
		message_vision("$N触动了机关！\n", this_player());
		message("vision","突然，暗门砰的一下弹开了，正巧撞在"+me->name()+"的头上\n",environment(me));
		i = (int)me->query_skill("dodge", 0);
		ging_cost = 700 / (int)me->query("int");
		qi_cost = 500 / (int)me->query("int");
		me->receive_damage("jing", ging_cost );
		me->receive_damage("qi", qi_cost );
		if(i>100||i<30) me->unconcious();
		return 1;
	}
}	

void dest()
{
	message("vision","画卷突然自动移回，又把暗门掩上了。\n","/d/beijing/aobai7");
	destruct(this_object());
}

