// Room: /d/wudujiao/baidu1.c

inherit ROOM;

void create()
{
        set("short", "百毒窟外");
        set("long", @LONG
这里是五毒教饲养毒物的地方，山壁旁有一个天然的石洞，里
面黑漆漆的看不清楚。一阵山风吹来，你闻到一股腥味。洞口有几
个五毒教弟子正在闲聊。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "south" : __DIR__"baidu2",
                "north" : __DIR__"wdsl4",
        ]));
        set("objects", ([
                 __DIR__"npc/jiaotu": 4,
        ]));

        set("coor/x", -44960);
	set("coor/y", -81070);
	set("coor/z", 20);
	setup();
}
int valid_leave(object me, string dir)
{
        int i;
        object ob;
        me=this_player();
        if(dir=="south")
        {
              if ((string)me->query("family/family_name")!="五毒教"
                    & objectp(present("jiao tu", environment(me))))
                    return notify_fail("五毒教徒忽然挡住你，厉声喝道：这位" +
                         RANK_D->query_respect(me) + "鬼头鬼脑的想干什么？\n");
        }
        return ::valid_leave(me, dir);
}

