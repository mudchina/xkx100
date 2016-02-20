// Room: /city/leitai.c
// Date: Feb.27 1998 by Java
inherit ROOM;
string look_shelf();
string do_quit(string arg);

void create()
{
	set("short", "擂台");
	set("long", @LONG
这是一个四丈见方的擂台。粗壮结实的木柱撑起一片平台，四角的
支柱上高挂着四副对联，四面的观众都能清楚地看到台上的手起脚落。
擂台角上有个兵器架(shelf) ，刀剑鞭棒样样俱全。
LONG );
        set("outdoors", "yangzhouw");
	set("item_desc", ([
		"shelf" : (: look_shelf :),
	]));

	set("exits", ([
		"up"        : __DIR__"wudao",
		"eastdown"  : __DIR__"wudao1",
		"westdown"  : __DIR__"wudao2",
		"southdown" : __DIR__"wudao3",
		"northdown" : __DIR__"wudao4",
	]));
	set("objects", ([
		__DIR__"npc/referee": 1,
	]));
	set("no_clean_up", 0);
	set("no_openshelf", 1);
	set("coor/x", -20);
	set("coor/y", -30);
	set("coor/z", 10);
	set("no_quest",1);
	setup();
}

string look_shelf()
{
	return 
"\n
一个很有年头的兵器架，红漆都剥落得差不多了。
架上摆满了: 
                 钢刀(blade)    长剑(sword)
                 钢杖(staff)    长鞭(whip)
                 铁锤(hammer)   长棍(club)
                 铁棒(stick)    板斧(axe)
                 钢钩(hook)     短兵(dagger)
                 暗器(throwing) 钢甲(armor)
                 长枪(spear)
                 
参加比武者可以按需要，随便拿取(take)使用。

                                侠客行擂台  敬启
\n";
}

void init()
{
//	add_action("do_yun","yun");
//	add_action("do_yun","exert");
	add_action("do_quit","attack");
	add_action("do_quit","hit");
	add_action("do_quit","fight");
	add_action("do_quit","qiecuo");
	add_action("do_quit","duanlian");
	add_action("do_quit","kill");
	add_action("do_quit","quit");
	add_action("do_quit","exit");
	add_action("do_quit","dazuo");
	add_action("do_quit","exercise");
	add_action("do_quit","learn");
	add_action("do_quit","xue");
	add_action("do_quit","practice");
	add_action("do_quit","lian");
	add_action("do_quit","study");
	add_action("do_quit","du");
	add_action("do_take","take");
	add_action("do_open","open");
	add_action("do_close","close");
}
int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me) )
                return notify_fail("裁判席只有被特邀才能进去。\n");
	me->set_temp("view_leitai",1);
	me->delete("no_get");
        return ::valid_leave(me, dir);
}
int do_yun(string arg)
{
	if (arg=="roar")
	{
        write(this_player()->query("name")+"，专心比武吧！\n");
	return 0;
	}
	return 1;
}
int do_quit(string arg)
{
        write(this_player()->query("name")+"，专心比武吧！\n");
	return 1;
}
int do_open()
{
	if(wizardp(this_player()))
	{
		message_vision("$N把兵器架启封了。\n", this_player());
		this_object()->delete("no_openshelf");
		return 1;
	}
	else return 0;
}
int do_close()
{
	if(wizardp(this_player()))
	{
		message_vision("$N拿了条封条把兵器架给封了。\n", this_player());
		this_object()->set("no_openshelf", 1);
		return 1;
	}
	else return 0;
}
int do_take(string arg)
{
	object obj,ob;
	ob = this_player();
	if(this_object()->query("no_openshelf"))
	{
		message_vision("非大比武的时候，兵器架给封住了。\n", ob);
		return 1;
	}
	if( !arg || arg=="" )
	{
		message_vision("$N站在兵器架前，还没想好要什么兵器。\n", ob);
		return 1;
	}
	switch (arg)
	{
		case "sword":
			obj = new("/clone/weapon/changjian1");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一口长剑。\n",ob);
			break;
		case "blade":
			obj = new("/clone/weapon/gangdao1");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一口钢刀。\n",ob);
			break;
		case "staff":
			obj = new("/clone/weapon/gangzhang1");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一杆钢杖。\n",ob);
			break;
		case "whip":
			obj = new("/clone/weapon/changbian1");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一条长鞭。\n",ob);
			break;
		case "stick":
			obj = new("/clone/weapon/stick1");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一条铁棒。\n",ob);
			break;
		case "club":
			obj = new("/clone/weapon/qimeigun1");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一条齐眉棍。\n",ob);
			break;
		case "hammer":
			obj = new("/clone/weapon/hammer1");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一把铁锤。\n",ob);
			break;
		case "axe":
			obj = new("/clone/weapon/axe1");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一柄板斧。\n",ob);
			break;
		case "throwing":
			obj = new("/clone/weapon/lianzi1");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一包铁莲子。\n",ob);
			break;
		case "dagger":
			obj = new("/clone/weapon/dagger1");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一把匕首。\n",ob);
			break;
		case "armor":
			obj = new("/clone/weapon/tiejia");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一副铁甲。\n",ob);
			break;
		case "hook":
			obj = new("/clone/weapon/hook1");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一柄钢钩。\n",ob);
			break;
                case "spear":
			obj = new("/clone/weapon/changqiang1");
			obj -> move(ob);
			message_vision("$N从兵器架上取下一杆长枪。\n",ob);
			break;			
        	default:
			message_vision("$N站在兵器架前，还没想好要什么兵器。\n", ob);
	}
	return 1;
}