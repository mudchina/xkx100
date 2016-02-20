// Room: /d/wudujiao/wandu1.c

inherit ROOM;

void create()
{
        set("short", "万毒窟外");
        set("long", @LONG
这里是五毒教饲养毒物的地方，山壁旁有一个天然的石洞，里
面黑漆漆的看不清楚。一阵山风吹来，你闻到一股腥味。有一个衣
衫褴褛的枯瘦老妇正靠在洞边打盹。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "south" : __DIR__"wandu2",
                "north" : __DIR__"wdsl3",
        ]));
        set("objects", ([
                  CLASS_D("wudujiao")+"/hehongyao": 1,
        ]));

        set("coor/x", -44970);
	set("coor/y", -81090);
	set("coor/z", 10);
	setup();
}
int valid_leave(object me, string dir)
{
        int i;
        object ob;
        me=this_player();
        if(dir=="south")
        {
            if( !present("tie shao", me)
                & objectp(present("he hongyao", environment(me))))
                return notify_fail("何红药身形一晃，忽然挡住你，厉声说道：这位" + RANK_D->query_respect(me) + "没有教主准许，不得进入本教圣地。\n");
        }
        return ::valid_leave(me, dir);
}
