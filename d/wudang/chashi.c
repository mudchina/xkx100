// By Marz 04/01/96

#include <ansi.h>
inherit ROOM;

void init();
int do_tap(string arg);
int do_sit(string arg);
int do_jump(string arg);
void delete_served(object me);
int valid_leave(object me, string dir);

void create()
{
        set("short", "茶室");
        set("long", @LONG
满屋的果香和茶香，沁人心脾。山西面的茶农们因感激武当弟子保
护他们免受土匪的骚乱和官府的苛捐杂税，每年开春采茶季节，总要送
来上好的茶叶。这茶叶由少女在三更至日出间采摘，并放在怀中用体温
焙制，得天地精华，汇处子体香，故名＂女儿香＂，据说喝了能提精补
神，十分珍贵。屋里四周得体地摆着些桌子(table)和椅子(chair)，坐
满了武当的男女弟子。南边有扇窗子(window)，景色宜人。
LONG );
        set("exits", ([
                "north" : __DIR__"donglang2",
        ]));
        set("item_desc", ([
            "table" : "一张典雅的桃木小桌，上面放着水果盘和饮茶器具。\n",
            "chair" : "一只青竹打制的靠椅，躺上去摇摇晃晃，好舒服耶！\n",
            "window" : "可以看得见东南远处桃花一片，拟似彩云盖地，让人神往。窗子下面就是广场．\n",
        ]));
        set("objects",([
                __DIR__"npc/xiaocui" : 1,
                __DIR__"obj/mitao" : 2,
                __DIR__"obj/dawancha" : 1,
        ]));
//        set("no_clean_up", 0);
        set("no_fight", 1);
	set("coor/x", -2030);
	set("coor/y", -930);
	set("coor/z", 90);
	setup();
}

void init()
{
        add_action("do_jump", "jump");
        add_action("do_tap", "tap");
        add_action("do_tap", "knock");
        add_action("do_sit", "sit");
}

int do_jump(string arg)
{

        object me = this_player();
        int dex = this_player()->query_dex();
        object ob;

    if (arg != "window" && arg != "out") return command("jump "+arg);

        me->delete_temp("marks/sit");
        me->delete_temp("tea_cup");

    message_vision("$N＂嗖＂地一声跳出窗户。\n", me);
    if ((dex <= 23)&&(random(3)<2) || (dex > 23)&&(dex <= 26)&&random(2) )
    {
        message_vision("结果＂啪＂地一声$N在下面的广场上摔了个结结实实。\n", me);
            if ( objectp(ob=present("mi tao", this_player())) )
            {
                message_vision("水蜜桃砸烂了，溅了$N一屁股桃汁。\n", me);
                destruct(ob);
                }
            if ( objectp(ob=present("xiang cha", this_player())) )
            {
                message_vision("怀里的香茶翻了，湿了$N一裤子茶水。\n", me);
                destruct(ob);
                }

                me->receive_damage("qi", 60, me);
                me->receive_wound("qi", 40, me);
                if (me->query_skill("dodge",1)<101)
                    me->improve_skill("dodge", random(3));
    } else if (dex <= 26)
    {
        message_vision("$N摇摇晃晃地落在下面的广场上，差点摔倒！\n", me);
                if (me->query_skill("dodge",1)<101)
                    me->improve_skill("dodge", random(2));
    } else
    {
        message_vision("$N提一口气，姿态潇洒地飘落在下面广场上！\n", me);
    }

    me->move(__DIR__"guangchang");

    return 1;
}

int do_tap(string arg)
{

        object me;
        object cui;

        if (!arg || (arg != "desk" && arg != "table"))
        {
                return notify_fail("你要敲什么？\n");
        }

        me = this_player();
        if( !objectp(cui = present("xiao cui", environment(me))) )
                return notify_fail("你敲了敲桌子，却还是没人理你。你突然感觉自己很无聊。\n");

        if( !me->query_temp("marks/sit") )
                return notify_fail("你敲了敲桌子，却没想到有对年轻人从桌底下钻出来，愕然地看着你，"
                        +"\n你突然感觉自己很愚蠢。\n");

    if( me->query_temp("marks/served") )
    {
        message_vision("小翠不耐烦地对$N说道：刚给你上过茶你接着就要，"+
                                "你是个Ｒｏｂｏｔ我可不是啊！\n", me);
        return notify_fail("");
    }

        message_vision("$N端坐在桌前，轻轻扣了下桌面，小翠莞尔一笑，过来招呼。\n", me);

        cui->serve_tea(me) ;

    me->set_temp("marks/served", 1);
//  remove_call_out("delete_served");
    call_out("delete_served", 10, me);

        return 1;
}


void delete_served(object me)
{
        if ( objectp(me) ) me->delete_temp("marks/served");
}


int do_sit(string arg)
{

        if ( !arg || (arg != "chair") )
                return notify_fail("你要坐什么上面？\n");

        if (this_player()->query_temp("marks/sit"))
                return notify_fail("你已经有了个座位了。\n");

        this_player()->set_temp("marks/sit", 1);
        return notify_fail("你找了个空位座下，等着上茶。\n");
}


int valid_leave(object me, string dir)
{
        if (  (dir == "north")
           && ( present("xiang cha", this_player())
                || present("mi tao", this_player()) )
           && objectp(present("xiao cui", environment(me))) )
        switch ( random(2) )
        {
        case 0:
         return notify_fail
                ("小翠把嘴一撇：吃饱了喝足了还不够，临走怀里还揣上一些，小女子也替您脸红呢！\n");
         break;
        case 1:
         message_vision("小翠对$N道了个万福：张真人吩咐，饮食不得带出茶房。", me);
         return notify_fail("\n");
         break;
        }

        me->delete_temp("marks/sit");
        me->delete_temp("tea_cup");
        return ::valid_leave(me, dir);
}
