// yaojishi.c 药剂室
// Winder Oct.10 1998

inherit ROOM;
int do_pullout(string arg);

void create()
{
        set("short", "药剂室");
        set("long", @LONG
这里是全真教制药、配药的地方。这间房间本来很大，只是
被前后左右堆放的药柜药箱挤的显得小多了。药柜已经很陈旧了，
不过是用上好的南海沉香木做成的，据说用这种木材做成的柜子
用来储藏东西不会遭虫蛀。药柜上面有个抽屉(drawer)。
LONG
        );
        set("sleep_room",1);
        set("exits", ([
                "east" : __DIR__"xianzhentang",
        ]));

        set("objects", ([
                CLASS_D("quanzhen")+"/zhangyao" : 1,
        ]));

        set("item_desc", ([
        "drawer": "一个抽屉，不知道是因为粗心还是什么原因，没有上锁。\n"
        ]) );

        set("count",1);
	set("coor/x", -2810);
	set("coor/y", 100);
	set("coor/z", 170);
	setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_pullout","pullout");
}

int do_pullout(string arg)
{
        object me=this_player();
        object ob;

        if( !arg || arg != "drawer" ) {
                return notify_fail("你要拉开什么？\n");
        }

        if (query("count")>0) {
        message_vision("$N趁着掌药道长转过身去，飞快地把抽屉拉开，里面好象有什么东西，\n",this_player());
        message_vision("还没来得及看，掌药道长又转过身来。只吓得$N一把抓起抽屉里的东西\n", this_player());
        message_vision("塞进怀里，然后装作抬头看药柜的木质，做出一副若无其事的样子。哈\n",this_player());
        message_vision("哈，掌药道长居然没发觉，$N长出了一口气，把无辜的表情收了回来。\n",this_player());
        add("count",-1);
        ob=new("/clone/medicine/vegetable/tianqi");
        ob->move(me);
        }
        else {
        message_vision("$N趁着掌药道长转过身去，飞快地把抽屉拉开，里面空空如也，原本在\n",this_player());
        message_vision("里面的东西好象已经被人取走了。\n", this_player());
        }

        return 1;
}