// Room: /d/nanshaolin/ting.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG"迎客亭"NOR);
	set("long", @LONG
苍松掩映之中，一座石亭赫然眼中。只见亭上匾额中龙飞凤舞的题
着『迎客亭』三个大字。凡江湖人士，在此需放下随身所带的兵器，才
可进入寺内。亭内有两名知客僧正在忙碌的招待来往的香客。
LONG );
	set("exits", ([
		"westdown" : __DIR__"fxjing",
		"northup"  : __DIR__"shanlu2",
		"east"     : __DIR__"shanlu1",
	]));
	set("outdoors", "nanshaolin");
	set("no_fight", 1);
	set("objects",([
		CLASS_D("nanshaolin") + "/fangtong" : 1,
		CLASS_D("nanshaolin") + "/fangkong" : 1,
		"/clone/misc/dache" : 1,
	]));
	set("coor/x", 1820);
	set("coor/y", -6350);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_quit","quit");
	add_action("do_quit","exit");
}

int do_quit()
{
	object ob = this_player();
	if (ob->query_condition("sl_lunzhi")>0)
	{
		write("你正在轮值，不能退出游戏。\n");
		return 1;
	}
	return 0;
}

int valid_leave(object me, string dir)
{
	object *inv;
	mapping myfam, mygen;
	int i;

	myfam = (mapping)me->query("family");
	if (!me->query("luohan_winner") && !present("yingxiong ling", me))
	if (me->query("gender") == "女性" && dir == "northup" )
	{
		if(objectp(present("fang tong", environment(me))))
			return notify_fail("方通伸手拦住你白眼一翻说道：千年以来，少林向不许女流擅入。"+RANK_D->query_respect(me) +"\n请下山去吧，免得自讨没趣。\n");
		if(objectp(present("fang kong", environment(me))))
			return notify_fail("方空迈步挡在你身前，双手合什说道：阿弥陀佛，这位" + RANK_D->query_respect(me) +"请留步，\n恕小寺不接待女客。女施主倘若一心向佛，何妨去峨眉山随喜？\n");
	}
	if((!myfam ||
		myfam["family_name"] != "少林派" &&
		myfam["family_name"] != "南少林派" ) &&
		dir == "northup")
	{
		inv = all_inventory(me);
		for(i=sizeof(inv)-1; i>=0; i--)
			if(inv[i]->query("weapon_prop") &&
				(inv[i]->query("equipped")))
			{
				if(objectp(present("fang tong",environment(me))))
					return notify_fail("方通拦住你说道：这位"+RANK_D->query_respect(me) +"请放下兵刃。少林千年的规矩，外客\n不得持兵刃上山。\n");
				if(objectp(present("fang kong", environment(me))))
					return notify_fail("方空迈步挡在你身前，双手合什说道：阿弥陀佛，这位"+RANK_D->query_respect(me) +"请收起\n兵刃。佛门清静之地，不便随意舞刀弄剑。还请施主鉴谅。\n");
			}
	}
	if (!me->query("muren_winner") && mapp(myfam) &&
		myfam["family_name"]== "南少林派" && 
		dir == "east" ) 
	{
		if(objectp(present("fang tong", environment(me))))
			return notify_fail("方通伸手拦住你躬身说道：这位师兄武功还未练好，不能下山，免得折了咱们南少林的名声！\n");
		if(objectp(present("fang kong", environment(me))))
			return notify_fail("方空伸手拦住你躬身说道：这位师兄武功还未练好，不能下山，免得折了咱们少林的名声！\n");
	}

	if (me->query_condition("sl_lunzhi")>0)
		return notify_fail("你正在轮值，不能离开！\n");

	return ::valid_leave(me, dir);
}

