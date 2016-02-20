//ROOM /d/xiakedao/dating.c

inherit ROOM;

int do_push(string arg);
void create()
{
        set("short", "大厅");
        set("long", @LONG
这是『侠客岛』的大厅，四周点满了牛油蜡烛，南面放着一个
大屏风。洞内摆着一百来张桌子，宾客正络绎进来，数百名黄衣汉
子穿索般来去，引导宾客入座。
LONG );
//        set("valid_startroom",1);
        set("no_fight","1");
        set("item_desc",([
                "pingfeng" : "这是一个用玉石作的屏风，非常漂亮，也许你能用手把它推(push)开。\n",
        ]));
        set("exits", ([
                "north" : __DIR__"shidong5",
                "east"  : __DIR__"shufang",
                "west"  : __DIR__"wuqiku",
        ]));
        set("objects",([
                __DIR__"npc/dizi" : 4,
        ]));
	set("coor/x", -3080);
	set("coor/y", -22110);
	set("coor/z", 0);
	setup();
        "/clone/board/xiake_b"->foo();
}

void init()
{
        add_action("do_push","push");
}

int do_push(string arg)
{
        object *inv,me=this_player();
        int n, i;
        n = me->query("neili");
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
        {
                if ((inv[i]->query("id")=="pai1") &&
                    (inv[i]->query_temp("own")!=me->query("id")))
                    return notify_fail("侠客岛弟子说道：这位" +
                      RANK_D->query_respect(me) + "好象不是侠客岛的客人吧？\n");
                if ((inv[i]->query("id")=="pai2") &&
                    (inv[i]->query_temp("own")!=me->query("id")))
                    return notify_fail("侠客岛弟子说道：这位" +
                      RANK_D->query_respect(me) + "好象不是侠客岛的客人吧？\n");
        }
        if( !arg || arg!="pingfeng")
        {
                write("你要推什么呀。\n");
                return 1;
        }
        message_vision("$N在屏风前站定，深吸一口气，两手紧握住屏风。\n", me);
        if (n >=100)
        {
                message_vision("$N丹田一运气，猛的一推，只见屏风之后，露出一条长长的甬道。\n", me);
                set("exits/south", __DIR__"yongdao3");
                me->set("neili",n-100);
                remove_call_out("close");
                call_out("close",5, this_object());
        }
        else
        {
                message_vision("$N丹田一运气，猛的一推，屏风却丝毫没动。\n", me);
                me->set("neili",0);
        }
        return 1;
}
void close(object room)
{
        message("visoin", "屏风自动又合上了。\n", room);
        room->delete("exits/south");
}