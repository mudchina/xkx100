// Room: /d/shenlong/cangku.c
// Last Modified by winder on Jul. 12 2002

inherit ROOM;

#include <ansi.h>
#include <localtime.h>
#include <globals.h>
#include <command.h>
//#include <REGIONS.h>

//#include "/d/REGIONS.h"
//#include "safeplaces.h"
#include "/d/shenlong/chaser/wanted_list.h"

#define SGNPCS "/kungfu/class/shenlong/"
#define CHASER "/d/shenlong/chaser/a"
#define THIEF  "/d/shenlong/chaser/hu.c"

int is_keeper(object, object);
void destroy_ob(object);
void create()
{
	set("short", "储藏室");
	set("long", @LONG
这里原来是一个长在山壁上的天然溶洞，后来被人改造成了一
个仓库。
LONG
	);
	set("exits", ([
	]));
	set("no_clean_up", 1);
	set("objects", ([
		"/clone/book/jiuyin1.c" : 1,
	]));
	setup();

// let those robbed stuffs go back to players
	call_out("refresh_stuff", 100);

// chase those players who take special weapons
	call_out("message_chaser", 100);
}

void refresh_stuff()
{
	object *inv, *invcon, *keepers, keeper, rum_ob;
	object weapon, armor;
	string *stuff_list = ({}), type;
	int period, i;

// destruct the unique stuffs

	inv = all_inventory(this_object());
	if( !sizeof(inv) )
	{
		delete("stuff_list");
		remove_call_out("refresh_stuff");
		call_out("refresh_stuff", 1000);
		return;
	}

	remove_call_out("refresh_stuff");
	call_out("refresh_stuff", 100 + random(100));

	for(i = 0; i < sizeof(inv); i++)
	{
		if( inv[i]->is_unique() )
		{
			inv[i]->add("sg/period", 1);
			if( (int)inv[i]->query("sg/period") > 5 )
			{
				keepers = filter_array(livings(), "is_keeper", this_object(), inv[i]);
				if (!sizeof(keepers)) continue;
				keeper = keepers[random(sizeof(keepers))];
				inv[i]->move(keeper);
				inv[i]->delete("sg/period");

				if( inv[i]->query("weapon_prop") )
				{
					if( weapon=keeper->query_temp("weapon"))
						"/cmds/std/unwield"->main(keeper, weapon->query("id"));
					"/cmds/std/wield"->do_wield(keeper, inv[i]);
				} else if( inv[i]->query("armor_prop/armor") )
					{
						type = inv[i]->query("armor_type");
						if( armor=keeper->query_temp("armor/"+type) )
							"/cmds/std/remove"->do_remove(keeper, armor);
						"/cmds/std/wear"->do_wear(keeper, inv[i]); 
					}

					message("channel:snow",HIM"【谣言】某人："+sprintf( "听说%s"+HIM+"好象落在%s的%s"+HIM+"手里了！"NOR,
					inv[i]->name(),
					to_chinese(explode(base_name(environment(keeper)), "/")[1]),
					keeper->name())+"\n",users());
					keeper->add("keep",1);
			}
		} else if( inv[i]->is_container() )
			{
				invcon = all_inventory(inv[i]);
				for(int m=0; m<sizeof(invcon); m++)
				{
					if( !invcon[m]->is_unique() )
						destruct(invcon[m]);
					else invcon[m]->move(this_object());
				}
				destruct(inv[i]);
			} else if( userp(inv[i]) )
				{
					inv[i]->move("/d/city/wumiao");
					continue;
				}
				else 
				destruct(inv[i]);
	}

// refresh the stuff_list
	inv = all_inventory(this_object());
	for(i = 0; i < sizeof(inv); i++)
	{
		stuff_list += ({inv[i]->query("name")});
	}
	if( sizeof(stuff_list) )
	set("stuff_list", stuff_list);
}

void destroy_ob(object ob)
{
	if( !ob ) return;
	if( !living(ob) )
	{
		call_out("destroy_ob", 20, ob);
		return;
	}

	message("vision", ob->name() + "急急忙忙地离开了。\n", environment(ob), ({ob}));

	destruct(ob);
}

#include "/d/shenlong/chaser/message_chaser.h";
