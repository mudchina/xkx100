// Room: /d/gumu/woshi.c
// Last Modifyed by Winder on Jan. 14 2002

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"卧室"NOR);
	set("long", @LONG
这里是小龙女居住的卧室，房中空空洞洞。右首是一块长条青石作
床 (bed)，床上铺了张草席，一幅白布当作薄被，此外除了一根人高的
绳索横过室中，室左立着一个粗糙木橱(chu)。
LONG	);
	set("item_desc", ([
		"bed" : HIC"一张由普通青石铺成的床，床角落处，有一块突起的石板，似可扳动。\n"NOR, 
		"chu" : HIY"一座普通之极的橱子。\n"NOR, 
	]));
	set("exits", ([
		"east" : __DIR__"mudao15",
	]));
	set("chu", 1);
	set("no_clean_up", 0);
	set("coor/x", -3220);
	set("coor/y", -40);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_tang", "tang");
	add_action("do_ban", "ban");
	add_action("do_open","kai");
	add_action("do_open","open");
	add_action("do_xian","xian");
}

int do_tang(string arg)
{
	object me=this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if ( arg == "bed")
	{
		message_vision(HIC"$N俯附身躺在青石制成的石床上面。\n"NOR,me);
		me->set_temp("marks/床", 1);
		return 1;
	}
	return notify_fail("你要躺在地上，小心着凉哦！\n");
}  

int do_ban(string arg)
{  
	object me=this_player();

	if (!me->query_temp("marks/床"))
		return notify_fail("你没躺床上，恐怕用不上力吧！\n");	
	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢！\n");
	if ( arg == "shiban" || arg == "stone")
	{
		if (me->query("neili") < 500)
			return notify_fail("你使出吃奶的劲力，但石板却纹丝不动。\n");
		message_vision(HIY "$N用力扳动突起的石板，只听得轧轧几响，石床已落入下层石室。\n"NOR,me);
		me->add("neili",-200);
		me->delete_temp("marks/床");
		me->move(__DIR__"shishi0");
		write(HIY"室顶石壁又慢慢自行推上了。\n"NOR);
		return 1;
	}
	return notify_fail("你要扳什么？\n");
}

int do_open(string arg)
{
	object ob, me=this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if ( arg=="chu")
	{
		if ( query("chu") == 1 )
		{
			if(!objectp(present("gold key", me)))	
				return notify_fail("你没有钥匙，怎么开啊？\n");
			message_vision("$N慢慢用金钥匙打开了橱门。\n",me);
			ob=new(__DIR__"obj/box");
			ob->move(environment(me));
			write("你发现橱内放着个长方形的铁盒子。\n");
			set("chu", 0);
			return 1;
		}
		else
		{
			write("你来晚了，橱门现在开着呢。\n");
			return 1;
		}
	}
	return notify_fail("你要开什么？\n");
}

int do_xian(string arg)
{
	object suo, me=this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着哪！\n");
	if ( arg =="box" || arg=="da tiehe" || arg =="tiehe")
	{
		if(!(present("da tiehe", environment(me)))) 
			return notify_fail("这里有铁盒么？\n");
		if(!objectp( present("silver key", me)))	
			return notify_fail("你没有钥匙，用什么开啊？\n");
		me->delete_temp("marks/铁盒");
		message_vision("$N用银钥匙开了锁，轻轻掀开了铁盒。\n",me);
		suo=new(__DIR__"obj/yinsuo");
		if(!clonep(suo))
			return notify_fail("你来晚了，盒子里面空无一物。\n");
		write("掀开铁盒，你发现里面放着一团冰绡般的物事。\n");
		suo->move(me);		
		return 1;
	}
	return notify_fail("你要掀开什么？\n");
}

