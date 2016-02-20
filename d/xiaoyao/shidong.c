// shidong.c
// Modified by Winder June.25 2000

inherit ROOM;
int do_push(string arg);

void create()
{
	set("short", "圆形石室");
	set("long", @LONG
这是座圆形石室，光亮从左边透来，但朦朦胧胧地不似天光。细看
天光处，那是一扇窗，竟然是镶在石壁的一块大水晶，约有铜盆大小，
光亮便从水晶中透入。一尾大虾在窗外游过。接着一条花纹斑烂的鲤鱼
在窗悠然而过。双眼帖着水晶往外瞧去，只见碧绿水流不住幌动，鱼虾
水族来回游动，极目所至，竟无尽处。原来处身之地竟在水底，当年造
石室之人花了偌大的心力，将外面的水光引了进来，这块大水晶更是极
难得的宝物。室中放着一只石桌，桌前有凳，桌上坚着一铜镜，镜旁放
着些梳子钗钏之属，看来竟是闺阁所居。铜镜(mirror)上生满铜绿，桌
上也是尘土寸积，不知已有多少年无人来此。
LONG );
	set("exits", ([
		"south" : __DIR__"damen",
		"east" : __DIR__"shiji2",
		"west" : __DIR__"shiji1",
	]));
	set("item_desc", ([
		"mirror" : "忽见东首一面斜置的铜镜反映光亮照向北隅，石壁\n上似有一道缝。\n",
	]));
	set("objects", ([
		CLASS_D("xiaoyao")+"/first" :1,
	]));
	set("coor/x", -50020);
	set("coor/y", -21040);
	set("coor/z", -40);
	setup();
}

void init()
{
        add_action("do_push", "push");
}

int do_push(string arg)
{
	object me;
	me = this_player();
	if (!arg||arg!="stone") return 0;
	write("你忙抢将过去，使力推那石壁。\n");
	if(random((int)me->query("kar")) < 10 ||
		me->query_skill("beiming-shengong",1) <= 40 )
	{
                write("那石壁推不动的。\n");
		return 1;
	};
	write("果然是一道门，缓缓移开，露出一洞来。\n");
	this_object()->set("exits/north","/d/xiaoyao/shishi3");
	return 1;
}