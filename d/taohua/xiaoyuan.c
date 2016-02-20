// Room: /d/taohua/xiaoyuan.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "听箫小院");
	set("long", @LONG
没有想到这里竟然会有这么幽雅的小院，假山回廊，花树盆景，无
一不是放置得极为合适，显然这里的主人非常熟悉布置，再联系到东、
西、南三面的桃花阵，足见主人熟通阴阳五行、变化生克之理。北面是
一个小山冈，转过山冈就是一大片的草地。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"east"  : __DIR__"bagua1",
		"west"  : __DIR__"bagua0",
		"south" : __DIR__"taohua1",
		"north" : __DIR__"caodi",
	]) );
	set("objects",([
		CLASS_D("taohua")+"/feng" : 1,
		__DIR__"obj/shizi" : 1,
	]));  
	set("outdoors","taohua");

	set("coor/x", 9010);
	set("coor/y", -3050);
	set("coor/z", 0);
	setup();
}
void init()
{
	object me=this_player();
	if (me->query_temp("step_count"))
	 me->delete_temp("step_count");
}
int valid_leave(object me, string dir)
{
	object *ob, *deep_ob;
	int i, j, drop_flag;

	if (dir == "west" || dir == "east")
	{
		if (!me->query_temp("bagua_1") &&
			me->query_skill("qimen-wuxing", 1) < 90)
			return notify_fail("你感觉这个桃花阵中暗藏八卦，隐隐生出阻力，将你推了回来！\n");
		ob = all_inventory(me);
		drop_flag = 0;
		for(i = 0; i < sizeof(ob); i++)
		{
			if (userp(ob[i]))
			{
				if (!drop_flag)
				{
					message_vision("$N看了看眼前这个复杂无比的八卦阵，决定丢下包袱，轻装上阵。\n", me);
					drop_flag = 1;
				}
				message_vision("$N将$n从背上放了下来，躺在地上。\n", me, ob[i]);
				ob[i]->move(this_object());
			}
			else
			{
				deep_ob = deep_inventory(ob[i]);
				for(j = 0; j < sizeof(deep_ob); j++)
				{
					if (userp(deep_ob[j]))
					{
						if (!drop_flag)
						{
							message_vision("$N看了看眼前这个复杂无比的八卦阵，决定丢下包袱，轻装上阵。\n", me);
							drop_flag = 1;
						}
				                message_vision(sprintf("$N丢下一%s$n。\n", ob[i]->query("unit")), me, ob[i]);
						ob[i]->move(this_object());
						break;
					}
				}
			}
		}
	}

	return ::valid_leave(me, dir);
}