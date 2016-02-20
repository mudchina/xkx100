// baidiao.c
// Last Modified by winder on May. 25 2001

inherit NPC;
void random_leave();
void create()
{
	set_name("大白雕", ({ "bai diao", "diao"}) );
	set("race", "飞禽");
	set("age", 18);
	set("long", "生长在大草原中的一种猛禽。\n");
	set("str", 28);
	set("cor", 24);
	set("combat_exp",180000);
	set("env/wimpy",50);
	set("chat_chance", 6);
	set("chat_msg", ({
		"大白雕在云层中盘旋，双翅掠过重重白云。\n",
		"云层中一道闪电劈下，在你眼前闪过一道金光。\n",
		(:random_leave:),
	}));
	set_temp("apply/attack", 28);
	set_temp("apply/armor", 28);

	setup();
}
void init()
{
	object ob;
	::init();
	ob=present("tu jiu",environment());
	if (!ob) ob=present("hei jiu",environment());
	if (ob)
	{
		set_leader(ob);
		kill_ob(ob);
	}
	add_action("do_kill","kill");
	add_action("do_kill","hit");
	add_action("do_kill","fight");
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
	message_vision("$N一声长鸣，振翅向"+dir+"飞去。\n",this_object());
	move(where[i]);
	tell_room(where[i],"一只大白雕飞了过来，在云层中盘旋。\n");
	return;
}
void do_kill(string arg)
{
	if (!arg||arg!="bai diao") return;
	random_leave();
	return;
}
