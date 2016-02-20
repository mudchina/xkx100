//Room: /d/dali/dahejieeast.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","大和街");
	set("long",@LONG
大道旁店铺林立，长街故朴，屋舍鳞次栉比，道上人来车往，一
片太平热闹景象。路口种了两棵大菩提树，树下有一个大洞(dong)。
一踏入巷中，阵阵茶花香气扑鼻而来。
LONG);
	set("outdoors", "dali");
	set("exits",([ /* sizeof() == 1 */
	    "north"  : __DIR__"baiyiziguan",
	    "south"  : __DIR__"baiyiminju",
	    "west"   : __DIR__"shizilukou",
	]));
        set("item_desc", ([
            "dong" : "黑乎乎的大洞，不知道有多深。\n",
        ]));
	set("no_clean_up", 0);
	set("coor/x", -39900);
	set("coor/y", -71030);
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
        object me;
        mapping fam;

        me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="dong" )
        {
           if( (fam = me->query("family")) && fam["family_name"] == "丐帮")
           {
               message("vision",
                        me->name() + "运起丐帮缩骨功，一弯腰往狗洞里钻了进去。",
                        environment(me), ({me}) );
               me->move("/d/gaibang/underdl");
               message("vision",
                        me->name() + "从洞里走了进来。\n",
                        environment(me), ({me}) );
                        return 1;
           }
           return notify_fail("这么小的洞，你钻得进去吗？\n");
       }
} 