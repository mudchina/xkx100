// Room: /d/taohua/taohua1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	int thd1, thd2, thd3, thd4;

	thd1 = random(4) + 1;
	thd2 = random(4) + 1;
	thd3 = random(4) + 1;
	thd4 = random(4) + 1;
	while (thd1 != 4 && thd2 != 4 && thd3 != 4 && thd4 != 4) {
		thd1 = random(4) + 1;
		thd2 = random(4) + 1;
		thd3 = random(4) + 1;
		thd4 = random(4) + 1;
	}
	set("short", "桃花阵");
	set("long", @LONG
这里是一片桃花的海洋。四周一望无际，全是盛开的桃花。微风拂
过，落英缤纷。周围静悄悄的。远处偶尔传来一声鸟叫。你心中不禁慌
乱起来：还是早点出去的好。
LONG
	);

	set("exits", ([
		"east" : __DIR__"taohua" + thd1,
		"west" : __DIR__"taohua" + thd2,
		"south" : __DIR__"taohua" + thd3,
		"north" : __DIR__"taohua" + thd4,
	]));
	set("no_drop","1");
	set("coor/x", 9010);
	set("coor/y", -3090);
	set("coor/z", 0);
	setup();
}

void init()
{
	object letter, ob=this_player();

	if ((ob->query("family/family_name") == "桃花岛" && ob->query_skill("count", 1) > 19) ||
		ob->query_skill("qimen-wuxing", 1) > 29)
		{
		write("由于你平常看惯了这些简易的阵法，所以不用细想，信步就走出了阵！\n");
		ob->move(__DIR__"xiaoyuan", 1);
		tell_room(environment(ob), "却见花影闪烁，树丛忽然现出一个缺口，" + ob->name() + "闪身而出。\n", ({ob}));
		return;
	}
	if ((letter = present("recommend letter", ob)) && letter->query("owner") == ob->query("id")) {
		write( "你正在疑惑怎么穿过这个桃花阵，一个作仆役打扮的哑巴忽然走了出来，检查了你身上的推荐信后示意你跟着他走。\n");
		write( "没过多久，你们就穿过了桃花阵，经过一个小小的院落后来到一座亭子跟前。\n");
		ob->move(__DIR__"jicui", 1);
		tell_room(environment(ob), "一个哑仆领着" + ob->name() + "走了过来。\n", ({ob}));
		return;
	}
	if (ob->query_temp("step_count") > 99) {
		ob->delete_temp("step_count");
		write("你在阵中累得精疲力尽，终因体力不支而昏了过去！\n");
		write( "迷迷胡胡中似乎有人把你抬出了阵，仿佛有个威严的声音喝道：“扔到海里去”。\n");
		ob->unconcious();
		ob->move(__DIR__"shore", 1);
		message("vision","忽然一个大潮涌了过来，将一个被水泡得半死的家伙冲到了岸边。\n", environment(ob), ob);
		return;
	}
	ob->add_temp("step_count", 1);
}

