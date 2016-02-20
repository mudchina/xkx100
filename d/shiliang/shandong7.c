// Feb. 6, 1999 by Winder
inherit ROOM;
int do_use(string arg);
int do_zuan(string arg);
void create()
{
        set("short", "山洞尽头");
	set("long", @LONG
你继续往里面走去，这里越发地黑起来，伸手不见五指，许
多蝙蝠在你耳边不停地怪笑，真令人毛骨悚然，你茫然不知道如
何是好。这里已经山洞尽头了，无路可走。
LONG
	);
	set("exits", ([
                "north" : __DIR__"shandong6",
	]));
	set("coor/x", 1600);
	set("coor/y", -1970);
	set("coor/z", 20);
	setup();
}
void init()
{
        add_action("do_use", "use");
        add_action("do_zuan", "zuan");
}
int do_use(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             write(
             "你点燃了火折，发现山洞右边有一道裂缝，似乎可以钻(zuan)出去。\n"
             );
             this_player()->set_temp("marks/钻1", 1);
             return 1;
       }
}
int do_zuan(string arg)
{
        object me;
        me = this_player();
        if (me->query_temp("marks/钻1") ) {
            message("vision", me->name() + "突然一脚踩空，身体直往下坠！\n",
                    environment(me), ({me}) );
            me->move(__DIR__"midao");
            me->unconcious();
            message("vision", me->name() + "从山洞里掉了下来。\n",
                    environment(me), ({me}) );
            this_player()->delete_temp("marks/钻1");
            return 1;
        }
        else {
            write("你想往哪儿钻?!\n");
            return 1;
        }
}