inherit ROOM;

void create()
{
	set("short", "长安戏院");
	set("long", @LONG
这里就是著名的长安戏院，几个戏子在台上 (stage)唱戏。台下黑
压压的一片都是人。唱到妙处，观众们禁不住大声喝采。东边是后台。
LONG );
	set("exits", ([
		"up"    : __DIR__"stage",
		"east"  : __DIR__"houtai",
		"south" : __DIR__"xichang1",
	]));
	set("item_desc", ([
		"stage" : "\n看到戏台，你突然有种想登台表演的冲动。\n" ,
	]));
	set("objects", ([
		__DIR__"npc/guanzhong":  5,
	]));
	set("guanzhong", 2);
	set("coor/x", -210);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	int i;
	object man, *ob;
	if(dir=="up")
	{
		if(!me->query_temp("hastryup"))
		{
			me->set_temp("hastryup",1);
			if((int)me->query("meili")>=40)
			{
				message_vision("只听哗啦啦一片掌声，观众们一起鼓掌。有人大声说道：\n静一静，请看这位"+RANK_D->query_respect(me)+ "表演。\n",me);
				return ::valid_leave(me, dir);
			}
			else
			{
				if(query("guanzhong") > 0)
				{
					add("guanzhong", -1);
					message_vision("\n突然观众一拥而上，对$N大叫道：凭你也敢上台闹事？老子宰了你这"+RANK_D->query_rude(me) + "！\n",me);
					if(!present("jia", environment(me)))
					{
						man=new(__DIR__"npc/guanzhong1");
						man->move(this_object());
					}
					if(!present("yi", environment(me)))
					{
						man=new(__DIR__"npc/guanzhong2");
						man->move(this_object());
					}
					if(!present("bing", environment(me)))
					{
						man=new(__DIR__"npc/guanzhong3");
						man->move(this_object());
					}
					if(!present("ding", environment(me)))
					{
						man=new(__DIR__"npc/guanzhong4");
						man->move(this_object());
					}
					if(!present("wu", environment(me)))
					{
						man=new(__DIR__"npc/guanzhong5");
						man->move(this_object());
					}
					ob = all_inventory(this_object());
					for(i=0; i<sizeof(ob); i++)
					{
						if( !userp(ob[i]) )
						{ 
							ob[i]->set_leader(me);
							ob[i]->kill_ob(me);
							me->fight_ob(ob[i]);
						}
					}
				}
				return notify_fail("观众们一阵倒彩。\n");
			}
			return notify_fail("观众们拼死也不让你上台。\n");
		}
		message_vision("$N拼死冲上台去。\n",this_player());
		return ::valid_leave(me, dir);
		} 
	return ::valid_leave(me, dir);
}
