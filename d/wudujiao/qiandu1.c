// Room: /d/wudujiao/qiandu1.c

inherit ROOM;

void create()
{
        set("short", "千毒窟外");
        set("long", @LONG
这里是五毒教饲养毒物的地方，山壁旁有一个天然的石洞，里
面黑漆漆的看不清楚。一阵山风吹来，你闻到一股腥味。洞口站着
几个五毒教弟子。
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "south" : __DIR__"wdsl4",
                "north" : __DIR__"qiandu2",
        ]));
        set("objects", ([
                __DIR__"npc/dizi": 4,
        ]));

        set("coor/x", -44960);
	set("coor/y", -81030);
	set("coor/z", 20);
	setup();
}
int valid_leave(object me, string dir)
{
    int i;
    object ob;
    me=this_player();
    if(dir=="north")
    {
    if ((string)me->query("family/family_name")!="五毒教"
        & objectp(present("di zi", environment(me))))
          return notify_fail("五毒教弟子忽然挡住你，厉声喝道：这位" +
           RANK_D->query_respect(me) + "鬼头鬼脑的想干什么？\n");
    }
    return ::valid_leave(me, dir);
}

