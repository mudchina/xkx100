// hollow.c

inherit ROOM;

void create()
{
        set("short", "雪坑");
        set("long", @LONG
这是大雪山脚下的一个雪坑。丢满了各种杂物， 还有丐帮弟
子收集的破铜烂铁等。坑边上有一个小洞(dong)。
LONG );
        set("exits", ([ /* sizeof() == 1 */
            "up"   : __DIR__"sroad3",
        ]));
        set("item_desc", ([
            "dong"   : "一个深邃幽暗的洞穴。\n",
        ]));
        set("objects",([
                __DIR__"npc/zhizhu" : 1,
        ]));
	set("coor/x", -30000);
	set("coor/y", -10000);
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
                        me->name() + "运起丐帮缩骨功，一弯腰往洞里钻了进去。\n",
                        environment(me), ({me}) );
               me->move("/d/gaibang/underxs");
               message("vision",
                        me->name() + "从洞里走了进来。\n",
                        environment(me), ({me}) );
                        return 1;
           }
           else  return notify_fail("这么小的洞，你钻得进去吗？\n");
       }
}