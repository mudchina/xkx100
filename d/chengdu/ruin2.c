// Room: /d/chengdu/ruin2.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "丐帮分舵");
	set("long", @LONG
这里是一栋破旧大宅的正厅，北面的墙壁跟屋顶已经整个坍塌了，
凉飕飕的冷风从北边的缺口直灌进来，另你觉得意外的是，这里清扫得
相当整洁，地上用乾草整整齐齐地铺著一个床(bed)。
LONG	);
	set("exits", ([
		"east": __DIR__"ruin1"
	]));
	set("item_desc", ([
		"bed"  : "你低头一看，发现床铺底下居然有个深幽的洞(dong)！\n",
		"dong" : "这是一个黑乎乎的洞口，不知道里面有多深。\n",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/obj/jiaohuaji" : 1,
		FOOD_DIR"jitui" : 1,
		FOOD_DIR"jiudai": 1,
	]));
	set("coor/x", -8080);
	set("coor/y", -3040);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_enter", "enter");
	add_action("do_enter", "zuan");
}

int do_enter(string arg)
{
	object me = this_player();
	mapping fam;

	if( !arg || arg=="" ) return 0;
	if( arg=="dong" )
	{
		if( (fam = me->query("family")) && fam["family_name"] == "丐帮")
		{
			message("vision", me->name() + "运起丐帮缩骨功，一弯腰往洞里钻了进去。\n", environment(me), ({me}) );
			me->move("/d/gaibang/undercd");
                	message("vision", me->name() + "从洞里走了进来。\n", environment(me), ({me}) );
			return 1;
		}
		else 
			return notify_fail("这么小的洞，你钻得进去吗？\n");
	}
}
