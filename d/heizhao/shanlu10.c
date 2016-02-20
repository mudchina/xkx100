// Room: /heizhao/shanlu10.c
// Date: Dec. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "山间平地");
	set("long", @LONG
这里有个极大的喷泉，高达二丈有余，奔雪溅玉，一条巨大的
水柱从石孔中直喷上来，飞入半空，这喷泉是下面溪水与瀑布的源
头。侧面山壁陡立，山上林荫如盖，似有一樵夫伐木其间。山边一
条手臂粗细的长藤(teng)，沿峰而上。仰头上望，见山峰的上半截
隐入云雾之中，不知峰顶究有多高。
LONG );
	set("outdoors", "taoyuan");
	set("no_clean_up", 0);
	set("resource/water", 1);
	set("objects", ([
		CLASS_D("dali")+"/yideng/qiao" : 1,
	]));
	set("exits", ([
		"down"   : __DIR__"pububian",
	]));
	set("coor/x", -5020);
	set("coor/y", -1260);
	set("coor/z", 30);
	setup();
}

int valid_leave (object who, string dir)
{
	if(dir == "down")
	{
		message_vision(HIY"$N顺水流冲舟而下。\n"NOR, who);
	}
	return ::valid_leave(who, dir);
}

void init()
{
        add_action("do_climb","climb");
}

int do_climb(string arg)
{
	object me = this_player();
	int n;
	n = me->query_str();
	if ( !arg || arg != "teng")
	{
		write("你要爬什么呀? \n");
		return 1;
	}
	message_vision("$N深吸了一口气，慢慢沿着长藤的向上爬。\n", me);
	if(n > 35)
	{
		message_vision("$N爬了半天，终于爬了上来，$N真是高兴。\n", me);
		this_player()->move(__DIR__"shanding");
	}
	else
	{
		message_vision("$N爬了一会，太累了，不小心滑了下来。\n", me);
		me->receive_damage("qi",15);
		me->receive_wound("qi",10);
	}
	return 1;
}