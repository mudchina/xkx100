// Room: /d/huangshan/caishi.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "采石峰");
	set("long", @LONG
相传是女娲采石补天所取天下山石中精英所在，山色与别山迥异，
竟似有五色，山上树木也分外茂密，山藤蔓绕，由于游人到松谷庵后多
半力竭，加之这里山藤环绕，甚是难走，所以以无游人到此。远远看见
轩辕峰，却已无力过去。
LONG
	);
	set("exits", ([ 
		"westdown" : __DIR__"songgu",
		"east"     : __DIR__"xuanyuan",
	]));
	set("outdoors", "huangshan");
	setup();
}
void init()
{
	add_action("do_chop","chop");
}

int do_chop(string arg)
{
	object obj, me = this_player();

	if(!arg || arg=="")
	{
		write("你要砍开什么？\n");
		return 1;
	}
	if( arg == "vine" || arg == "山藤")
	{
		if( !objectp(obj = me->query_temp("weapon"))) 
		{
			write("你空着手，砍什么砍？\n");
			return 1;
		}
		if( (string)obj->query("skill_type") == "sword" ||
			(string)obj->query("skill_type") == "blade" ||
			(string)obj->query("skill_type") == "axe" )
		{
			if( !query("exits/east") )
			{
				set("exits/east", __DIR__"xuanyuan");
				message_vision(sprintf("$N用手中的%s砍出一条向北的路。\n", obj->name()), me);
				me->start_busy(1);
			}
			else
				message_vision(sprintf("$N用手中的%s砍向环绕的山藤。\n",obj->name()), me);
		}
		else
			message_vision(sprintf("$N用手中的%s向蔓绕的山藤一顿乱砍。\n",obj->name()), me);
	}
	else write("你要砍开什么？\n");
	return 1;
}

void reset()
{
	::reset();
	delete("exits/east");
}
