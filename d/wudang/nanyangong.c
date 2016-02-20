//Room: nanyangong.c 南岩宫
//Date: Sep 29 1997

#include <ansi.h>
inherit ROOM;

void close_andao();
string look_xiang();
int do_move(string arg);

void create()
{
      set("short","南岩宫");
      set("long",@LONG
这里是就是南岩宫。此宫半卧悬崖之下。殿内三清坐像金光闪闪，
气宇轩昂。殿内天井处芳草迷径，百卉争妍。
    有几个装束醒目的武当三代弟子从这匆匆走过。南面高台就是真武
剑阵。叛师或半路投师者珍重。
LONG);
      set("exits",([ /* sizeof() == 1 */
          "out"    : __DIR__"shizhu",
          "southup": __DIR__"gaotai",
      ]));
      set("item_desc",([
          "三清坐像" :       (: look_xiang :),
      ]));
      set("no_clean_up", 0);
      set("coor/x", -2040);
	set("coor/y", -960);
	set("coor/z", 90);
	setup();
}

int valid_leave(object ob, string dir)
{
        mapping myfam;
        myfam = (mapping)ob->query("family");
        if ((int)ob->query("combat_exp",1)<10000 && (dir == "southup"))
            return notify_fail("外面的真武剑阵威力太大，你被内力鼓荡，不能上去。\n");
        if ((!myfam || (myfam["family_name"] != "武当派")) && (dir == "southup"))
            return notify_fail("非武当弟子，不能试演真武剑阵。\n");
        return 1;
}

void init()
{
        add_action("do_move", "move");
}

string look_xiang()
{
        return "三清坐像纯铜打就，镀以纯金，光照满殿。只是好象三个坐像摆得并不很整齐。\n";
}

int do_move(string arg)
{
        object room, ob;

        ob = this_player();
        if( !arg || arg!="xiang" ) return notify_fail("这里的摆设不能乱动！\n");
        message_vision(HIC"$N走到三清坐像背后，用力使劲推移老君像，慢慢的推着，终于推动了……\n像下露出一个大洞，几排石阶往下伸去，从这里分明通向一个暗道。\n"NOR, ob);
        set("exits/down", __DIR__"nanyan0");
        message_vision(HIC"$N毫不犹豫一纵而下……\n\n\n"NOR,ob);

        if( room = find_object(__DIR__"nanyan0") )
        {
           room->set("exits/up", __FILE__);
           message("vision", "天花板忽然发出轧轧的声音，露出一个向上的楼梯。\n",room );
        }
        ob->move(__DIR__"nanyan0");
        remove_call_out("close_andao");
        call_out("close_andao", 3);
        return 1;
}

void close_andao()
{
    object room;
    int i;

    if (!query("exits/down")) return;
    message("vision","只听乒地一声响，老君像自动移回原处。\n", this_object() );
    if( room = find_object(__DIR__"nanyan0") )
    {
        room->delete("exits/up");
        message("vision","只听乒地一声响，向上的洞口自动严严实实地关了起来。\n",room);
    }
    delete("exits/down");
}
