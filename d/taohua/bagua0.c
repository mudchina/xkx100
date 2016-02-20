// Room: /d/taohua/bagua0.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "八卦桃花阵");
	set("long", @LONG
这是一片茂密的桃花丛，你一走进来就迷失了方向。眼前是一排桃
花树，中间露出一条小径。
LONG
	);
	set("outdoors","taohua");
	set("exits", ([
		"east" : __DIR__"bagua1",
		"west" : __DIR__"bagua1",
		"south" : __FILE__,
		"north" : __FILE__,
	]));
	set("coor/x", 8800);
	set("coor/y", -3500);
	set("coor/z", 0);
	setup();
}

void init()
{
	object ob = this_player();
	int step, temp, count;

/*	if (!ob->query_temp("bagua_1")) {
		write("你感觉这个桃花阵中暗藏八卦，隐隐生出阻力，将你推了回来！\n");
		ob->move(__DIR__"xiaoyuan", 1);
		return;
	}*/
	if (ob->query_skill("qimen-wuxing", 1) > 99) {
		write("由于你已经精研了九宫八卦的变化，所以略做思考就走出了阵！\n");
		ob->move(__DIR__"road1", 1);
		tell_room(environment(ob), "却见花影闪烁，树丛忽然现出一个缺口，" + ob->name() + "闪身而出。\n", ({ob}));
		return;
	}
	if (!ob->query_temp("bagua_start")) {
		ob->set_temp("bagua_start", 1);
		ob->set_temp("bagua_step", 1);
		ob->set_temp("bagua_temp", 0);
		ob->set_temp("bagua_count", 1);
	}
	temp = ob->query_temp("bagua_temp");
	count = ob->query_temp("bagua_count");
	temp = temp * 2;
	if (count < 3) {
		count++;
	}
	else
	{
		count = 1;
		step = ob->query_temp("bagua_step");
		if (temp == ob->query_temp("bagua_" + step)) {
			if (step == 8) {
				ob->delete_temp("bagua_start");
				ob->delete_temp("bagua_step");
				ob->delete_temp("bagua_temp");
				ob->delete_temp("bagua_count");
				write("你倒踩八卦，直扑生门，眼前现出一道门户，你赶忙踏了过去。\n");
				ob->move(__DIR__"road1", 1);
				tell_room(environment(ob), "却见花影闪烁，树丛忽然现出一个缺口，" + ob->name() + "闪身而出。\n", ({ob}));
				return;
			}
			write("你发现刚才走过的路径暗合八卦，心中若有所悟！\n");
			ob->add_temp("bagua_step", 1);
		}
		else {
			ob->delete_temp("bagua_start");
			ob->delete_temp("bagua_step");
			ob->delete_temp("bagua_temp");
			ob->delete_temp("bagua_count");
			write("你发觉自己踩错了方位，四周暗雾密布，只好赶快抢回起始点！\n");
			ob->move(__DIR__"xiaoyuan", 1);
			tell_room(environment(ob), "却见花影闪烁，树丛忽然现出一个缺口，" + ob->name() + "踉跄着退了出来。\n", ({ob}));
			return;
		}
		temp = 0;
	}
	ob->set_temp("bagua_temp", temp);
	ob->set_temp("bagua_count", count);
}
