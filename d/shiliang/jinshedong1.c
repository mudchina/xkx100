// Feb. 6, 1999 by Winder
#include <room.h>
#include <ansi.h>
inherit ROOM;
int do_break(string arg);
int do_ba(string arg);
void create()
{
        set("short", "石室");
        set("long", @LONG
你来到另一间石室内，突然发现墙上有个剑柄。石壁(shibi)看
上去不是很结实。
LONG
        );
        set("exits", ([
                "west" : __DIR__"jinshedong",
        ]));
       set("item_desc",([
            "剑柄" : "这是一个很奇怪的剑柄，不知道有没有剑身。你试着去拔它。\n",
            "shibi" : "也许你可以打开(break)它。\n",
             ]));
	set("jiancount",1);
        set("no_clean_up",0);
        set("coor/x", 1590);
	set("coor/y", -1980);
	set("coor/z", 10);
	setup();
}
void init()
{
    add_action("do_break", "break");
    add_action("do_ba", "ba");
}
int do_break(string arg)
{
    int n;
    n = this_player()->query("neili");
    if( !arg || arg!="shibi" ) {
        write("你不是超人，怎么乱来啊？\n");
        return 1;
    }
    message_vision(
    "$N走到石壁前，大吼一声，一掌击过去。\n", this_player());
        
    if (n>=1000) {
        message_vision(
        "$N只听一声巨响，$N把石壁震开一个大洞！\n", this_player());
        set("exits/north", __DIR__"shandao1");
        this_player()->set("neili",n-1000);
        remove_call_out("close");
        call_out("close", 10, this_object());
    }
    else {
        message_vision(
        "$N大吼一声“开！”，结果什么也没发生。看来$N的内力不够强。\n", this_player());
        this_player()->set("neili",0);
    }
    return 1;
}
void close(object room)
{
    message("vision","石壁忽然间很神秘得合上了。\n", room);
    room->delete("exits/north");
}
int do_ba(string arg)
{        object jian;
         object me;
         me = this_player();
         if( !arg || arg=="" ) {
message_vision("你想拔什么？\n", me);
return 1;
}
if( arg=="剑柄"||arg=="jian" ){
        if(query("jiancount") < 1)
        return notify_fail("你伸出手去拔那剑柄。不料却扑了个空，看样子剑已经被人取走了。\n");
        if( (int)me->query("str") < 28 )
        return notify_fail("你的臂力太小，使出吃奶的劲，剑柄依然纹丝不动。\n");
        if( (int)me->query("neili") < 2000 )
        return notify_fail("你的内力不够了，拔不动剑柄。\n");
        jian = new("/clone/weapon/treasure/jinshejian");
        if (jian->volate_unique()) 
        {
        	destruct(jian);
        return notify_fail("你伸出手去拔那剑柄。不料却扑了个空，看样子剑已经被人取走了。\n");
        }
	message_vision(
        HIW "$N凝神静气，默运玄功，神游物外，一时间仿佛入定了。\n"+
            "突然间$N眼中精光大盛，提起全身的潜力，猛地拔向那剑\n"+
            "柄。刹那间，风云为之变色，鬼神为之哭泣，只见一柄闪\n"+
            "着怪异碧色的蛇形长剑至石壁中飞将而出！！！\n"NOR, me);
        me->add("neili", -2000);
        jian->move(me);
        add("jiancount",-1);
        return 1;
        }else
        message_vision(
        "你望着石壁上的剑柄直发愣.....\n", me);
	return 1;	     
}
void do_jian()
{
	set("jiancount",1);
}
int valid_leave(object me, string dir)
{
        tell_object(this_player(),WHT "冥冥间，虚空中有个声音告诉你：此间有一不祥之物。 \n"+
                                      "此物一出，人神共怖，稀世宝物，世间独一。\n"NOR,this_player());
        return 1;
}
