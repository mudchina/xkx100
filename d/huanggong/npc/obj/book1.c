// book1.c
inherit ITEM;

int do_move(string arg);

void init()
{
	add_action("do_move", "move");
}

void create()
{
	set_name("帛书", ({"book"}));
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "\n一封精装的<<论语>>\n");
		set("unit", "幅");
		set("material", "paper");
		set("no_get", "\n住手,你岂可在此胡闹!下去!\n");
	}
	setup();
}

int do_move(string arg)
{
	object me;
	object door;
	string dir;
	me = this_player();
	if (!arg||arg=="") return 0;
	if( arg=="book" ) {
		if(!me->query_temp("doorisok"))
		{
			me->set_temp("doorisok", 1);
			message_vision(
"\n$N试著移动画卷，发现它可以左右推动...\n", this_player());
		}
		if(!objectp(present("door", environment(me))))
		{
			message_vision(
"$N轻轻地挪动画页，突然一扇暗门出现在$N眼前。\n", this_player());
			door = new("/d/beijing/obj/door");
			door->move("/d/huanggong/shufang");
		}
	}
	if( sscanf(arg, "book %s", dir)==1 )
	{
		if( dir=="left" )
		{
			message_vision(
"$N将画卷往左移，只听轧轧几声，画卷又移回原位。\n", this_player());
			if(!me->query_temp("pushdoor"))
				me->set_temp("pushdoor", 1);
			else
				me->set_temp("pushdoor", 0);
			return 1;
		}
		if( dir=="right" )
		{
			message_vision(
"$N将画卷往右移，只听轧轧几声，画卷又移回原位。\n", this_player());
			if (me->query_temp("pushdoor") )
			{
				me->set_temp("doorisok", 1);
				me->delete_temp("pushdoor");
			}
		return 1;
		}
		else {
			write("你要将画卷移向那个方向？\n");
			return 1;
		}
	}
	return 1;
}


