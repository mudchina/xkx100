// cundaota4.c 存道塔顶
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_dian(string arg);

void create()
{
        set("short", "存道塔顶");
        set("long", @LONG
这里是存道塔的塔顶，塔梯到这里就到了尽头。墙壁上开着几
个窗户(window)，一个中年道人正捧着一本书苦苦研读。天色昏暗，
桌上摆放着一支蜡烛(candle)，却没有点着。
LONG
        );
        set("exits", ([
                "eastdown" : __DIR__"cundaota3",
        ]));
        set("objects", ([
                CLASS_D("quanzhen")+"/zhangjing" : 1,
        ]));

        set("item_desc", ([
        "window": "窗外白云飘过，似乎你一伸手就可以抓住一片。\n",
        "candle": "一支普通的蜡烛，已经点的只剩一小半了。\n"
        ]) );

        set("count",1);
	set("coor/x", -2790);
	set("coor/y", 130);
	set("coor/z", 200);
	setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_dian","dian");
}

int do_dian(string arg)
{
        object ob;
        object me=this_player();

        if (!arg || arg != "candle")
                return notify_fail("你要点燃什么？\n");

        if ( query("count")>0 &&
        present("zhangjing", environment(me)) &&
        living(present("zhangjing", environment(me))) ) {
                message_vision(HIG"$N走上前去，打着火把蜡烛点燃，屋里顿时亮堂了许多。\n"NOR,this_player());
                message_vision("掌经道长抬起头，好象刚从沉思中恢复过来似的，道：天\n",this_player());
                message_vision("色已晚了吗，唉，我读这本道德经竟然连天色也忘记了。\n",this_player());
                message_vision("好，多谢这位"+RANK_D->query_respect(me)+"了，我身上这东西是掌药师弟送给我\n",this_player());
                message_vision("的，也不知道有什么用，现在送给你啦。\n",this_player());
                add("count",-1);
                ob=new("/clone/medicine/vegetable/moyao");
                ob->move(me);
        }
        else {
                message_vision("$N走上前去，打着火把蜡烛点燃，屋里顿时亮堂了许多。\n",this_player());
        }
        return 1;
}