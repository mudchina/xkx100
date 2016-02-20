// Room: /binghuo/shanlu1.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "石山小路");
	set("long", @LONG
走在火山石的寸草片叶不生的山路上。东下就是茂密的大树林了。
往上是上山的路，山脚下树林子边上露出一个石洞(dong)。洞边树下
阵阵清香，细审原来是从树下一大丛不知名的花朵上传出。洞中黑呼
呼的什么也瞧不见。
LONG );
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	set("item_desc", ([
		"dong" : "这个原来是熊窝的石洞被人清洁后成为岛上最好的居所。\n",
	]));
	set("exits", ([
		"southeast" : __DIR__"shulin3",
		"northup"   : __DIR__"shanlu2",
	]));
	setup();
}

void init()
{
        add_action("do_enter", "enter");
}

int do_enter(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="dong" ) 
	{
		message("vision",
			me->name() + "一弯腰往洞里走了进去。\n",
			environment(me), ({me}) );
                me->move(__DIR__"inhole1");
                message("vision",
			me->name() + "从洞外走了进来。\n",
                	environment(me), ({me}) );
		return 1;
	}
}	
