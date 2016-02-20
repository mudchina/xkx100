// heijiu.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void random_leave();
void random_eat();
void create()
{
	set_name("黑鹫", ({ "hei jiu"}) );
	set("race", "飞禽");
	set("age", 16);
	set("long", "漠北一种凶猛的飞鸟，以腐尸为食。\n");
	set("str", 24);
	set("cor", 24);
	set("combat_exp",50000);
	set("chat_chance", 6);
	set("chat_msg", ({
		"黑鹫在你头顶盘旋，似乎在寻找下手的机会。\n",
		"黑鹫落在你前面不远的岩石上，不怀好意的盯住你。\n",
		(:random_leave:),
		(:random_eat:),
	}));
	set_temp("apply/attack", 20);
	set_temp("apply/armor", 20);
	setup();
}
void init()
{
	object ob;
	::init();
	if (interactive(ob=this_player())&&!is_fighting())
	{
		remove_call_out("eat_corpse");
		call_out("eat_corpse",1,ob);
	}
	add_action("do_kill","kill");
	add_action("do_kill","hit");
	add_action("do_kill","fight");
}
void eat_corpse(object ob)
{
	object corpse;
	corpse=present("corpse",environment());
	if (corpse)
	{
		message_vision("$N一点点啄食着$n，时不时振起散乱的羽毛。\n",this_object(),corpse);
		return;
	}
	return;
}
void random_leave()
{
mapping default_dirs = ([
	"east":         "东",
	"west":         "西",
	"south":        "南",
	"north":        "北",
	"eastup":       "东边",
	"westup":       "西边",
	"southup":      "南边",
	"northup":      "北边",
	"eastdown":     "东边",
	"westdown":     "西边",
	"southdown":    "南边",
	"northdown":    "北边",
	"southeast":    "东南",
	"southwest":    "西南",
	"northeast":    "东北",
	"northwest":    "西北",
	"up":           "上",
	"down":         "下",
	"out":          "外",
	"enter":        "里",
]);

	mapping exits;
	string *dirs,*where,dir;
	int i;

	if( !mapp(exits = environment()->query("exits")) ) return;
	dirs = keys(exits);
	where=values(exits);
	i=random(sizeof(dirs));
	
	if( !undefinedp(default_dirs[dirs[i]]) ) dir = default_dirs[dirs[i]];
	else dir =dirs[i];
	message_vision("$N一声惊叫，振翅向"+dir+"飞去。\n",this_object());
	move(where[i]);
	tell_room(where[i],"一只黑鹫飞了过来，在空中盘旋。\n");
	return;
}
void do_kill(string arg)
{
	if (!arg||arg!="hei jiu") return;
	random_leave();
	return;
}
void random_eat()
{
	object corpse;
	corpse=present("corpse",environment());
	if (corpse)
	{
		message_vision("$N一点点啄食着$n，时不时振起散乱的羽毛。\n",this_object(),corpse);
		return;
	}
	return;
}
