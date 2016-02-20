// pubu.c 瀑布

inherit ROOM;

#include <ansi.h>

int do_jump(string arg);
int do_plump(string arg);
void create()
{
        set("short", "瀑布");
        set("long", @LONG
你猛听得水声响亮，轰轰隆隆，便如潮水大至一般，抬头一看，
只见一条大瀑布(pubu)，犹如银河倒悬，从高崖上直泻下来下面是万
丈悬崖(xuanya)，云雾弥漫，望不到尽头!!!
LONG  );
        set("exits", ([ /* sizeof() == 3 */
                "northdown" : __DIR__"road4",
        ]));
        set("outdoors", "xiakedao");
        set("item_desc",([
            "pubu"   : "你仔细一看，瀑布里面好象有出口，你似乎可以跳(jump)进去。\n",
            "xuanya" : "下面弥漫着烟雾，什么也看不见，你可不要跳(plump)下去呀！\n",
        ]) );
        set("no_clean_up", 0);
	set("coor/x", -3000);
	set("coor/y", -22060);
	set("coor/z", 50);
	setup();
}

void init()
{
        add_action("do_jump","jump");
        add_action("do_plump","plump");
}
int do_jump(string arg)
{
        int n;
        n = this_player()->query_skill("dodge",1);
        if( !arg || arg!= "pubu" )
          {
          write("不要在这里乱跳!\n");
          return 1;
        }
message_vision("$N在瀑布前站定，深呼一口气，突然跃起。\n", this_player());
        if(n >=80)
        {
message_vision("只见$N脚尖一点地，身子轻飘飘的跃进瀑布之中。\n", this_player());
            this_player()->move(__DIR__"yongdao1");
        }
        else if(n >=50)
        {
message_vision("只见$N使出全身的力量，身子再空中摇摇惶惶，终于落在瀑布里面。\n", this_player());
           this_player()->move(__DIR__"yongdao1");
        }
        else
        message_vision("只见$N高高跃起，还差很远呢! \n", this_player());
        return 1;

}
int do_plump(string arg)
{
        object ob;
        int new_gin;

        ob = this_player();
        new_gin = random( ob->query("max_gin")*3 );
        if ( new_gin > ob->query("gin") ) new_gin = ob->query("gin") + 1;
        if( !arg || arg!= "down")
        {
            write("你要跳什么呀? \n");
            return 1;
        }
        tell_object(ob,HIR"你不加思索，纵身跳下了悬崖。\n"NOR);
        message("visoin",NOR"只见" + ob->query("name") + "纵身跳下了悬崖。\n"NOR,environment(ob), ob);
        if((random((int)ob->query("kar")) <15 ) && ((int)ob->query_skill("dodge",1) < 30) )
        {
            ob->die();
            return 1;
        }
        ob->add("gin",0 - new_gin);
        ob->move(__DIR__"yadi");
        return 1;
}