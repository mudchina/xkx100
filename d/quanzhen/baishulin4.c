// baishulin4.c 柏树林
// Winder Oct.10 1998

inherit ROOM;
int do_kan(string arg);

void create()
{
        set("short", "柏树林");
        set("long", @LONG
这里是树林的边缘，光线亮的多了。参天的柏树也稀疏了很多。
旁边有一丛灌木(frutex)杂生。灌木再往前，就是悬崖了。
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "west" : __DIR__"baishulin3",
                "southdown" : __DIR__"baishulin2",
        ]));
        set("no_clean_up", 0);
        set("count",1);
        set("item_desc", ([
            "frutex": "一丛你叫不出名字的灌木，其中夹杂着很多小刺。\n"
        ]) );

	set("coor/x", -3130);
	set("coor/y", 40);
	set("coor/z", 40);
	setup();
}

void init()
{
        add_action("do_kan","kan");
}

int do_kan(string arg)
{
        object me=this_player();
        object weapon;
        object ob;

        if( !arg || arg != "frutex" ) {
                return notify_fail("你要砍什么？\n");
        }

        if (!objectp(weapon = me->query_temp("weapon")))
                return notify_fail("不用家伙恐怕不行吧！\n");

        if (query("count")>0) {
        message_vision("$N拔出兵刃，走到灌木丛跟前一阵乱砍，把面前一些耸立的灌木\n",me);
        message_vision("砍倒以后，$N发觉下面生长着一棵什么小草，于是顺手拔了起来，\n", me);
        message_vision("没想到这东西下面连着好大一块根茎。\n",me);
        add("count",-1);
        ob=new("/clone/medicine/vegetable/fuling");
        ob->move(me);
        }
        else {
        message_vision("$N拔出兵刃，走到灌木丛跟前一阵乱砍，把面前一些耸立的灌木\n",me);
        message_vision("砍倒了。$N累的够呛。\n", me);
        }

        return 1;
}