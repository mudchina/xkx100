// Room: /yangzhou/shiliji4.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;
look_gaoshi();

void create()
{
	set("short","中央广场");
	set("long",@LONG
这里是城市的正中心，一个很宽阔的广场，铺着青石地面，十里长
街穿场而过。一些游手好闲的人在这里溜溜达达，经常有艺人在这里表
演。中央有一棵大榕树，盘根错节，据传已有千年的树龄，是这座城市
的历史见证。树干底部有一个很大的树洞(dong)。你可以看到北边有来
自各地的行人来来往往，南面人声鼎沸，一派繁华景象。东边连着甘泉
街。街西是通泗桥，桥头立着一块告示牌(gaoshi)，过桥就是通向扬州
官衙的道路。
LONG );
	set("outdoors", "yangzhouw");
	set("no_sleep_room",1);
	set("visitor", 0);
	set("item_desc", ([
		"dong"  : "这是一个黑不溜湫的大洞，里面不知道有些什么古怪。\n",
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"east"  : __DIR__"ganquanjie",
		"west"  : __DIR__"tongsiqiao",
		"south" : __DIR__"shilijie5",
		"north" : __DIR__"shilijie3",
		"down"	: __DIR__"lajichang",
	]));
	set("objects", ([
//		__DIR__"npc/xunbu" : 1,
		__DIR__"npc/liumang" : 4,
		__DIR__"npc/liumangtou" : 1,
		"/clone/misc/dache" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
}

void init()
{
	if(userp(this_player())) 
	{
		this_object()->add("visitor", 1);
		if(this_object()->query("visitor") % 500 == 0)
		{
			AUTOSAVE_D->create();
		}
	}
	add_action("do_enter", "enter");
//	UPDATE_D->check_user(this_player());
}

int do_enter(string arg)
{
	object me;
	me = this_player();

	if( !arg || arg=="" ) return 0;

	if( arg=="dong" ) 
	{
		if (me->is_busy()) return notify_fail("你正忙着呢。\n");
		message("vision",
			me->name() + "一弯腰往洞里走了进去。\n",
			environment(me), ({me}) );
		me->move("/d/gaibang/inhole");
		message("vision",
			me->name() + "从洞外走了进来。\n",
			environment(me), ({me}) );
		return 1;
	}
}

string look_gaoshi()
{
	string returnback;
	int count, sp;
	count=query("visitor");
	returnback="\n\n"+
	"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n"+
	"※※※※                                                  ※※※※\n"+
	"※※※※                    扬州府通告                    ※※※※\n"+
	"※※※※                                                  ※※※※\n"+
	"※※※※    即日通过此地共有"+chinese_number(count)+"人。";
	for (sp = 0; sp < 26-strlen(chinese_number(count)); sp++)
		returnback += " ";

	returnback += "※※※※\n"
	"※※※※                                                  ※※※※\n"+
	"※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※※\n";
	return returnback;
}
