// Room: /d/wudujiao/dongxue.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "洞穴");
        set("long", @LONG
这里是洞壁高处的一个小洞穴，地方小得只能容纳一个人存身。
这里黑洞洞的什么也看不见，只有洞旁的一株奇异的小草，叶面闪
得鬼魅异常。
LONG
        );

        set("objects", ([
                  __DIR__"obj/duanchang": 1,
        ]));

        set("coor/x", -44970);
	set("coor/y", -81120);
	set("coor/z", 10);
	setup();
}
void init ()
{
        add_action("do_fire","fire");
        add_action("do_fire","dian");
        add_action("do_insert","insert");
        add_action("do_climb","climb");
}

int do_fire (string arg)
{
        object me = this_player();
        if (!arg || arg!="huo ba")
        return notify_fail ("你想点燃什么？\n");

        if (!present(arg,me))  return notify_fail("你身上没有这样东西。\n");
        message_vision ("$N嚓的一声点亮一支火把！\n\n",me);
        message_vision ("刹那间四周被照得清清楚楚！\n",me);
        this_object()->recreate();
//  message_vision ("\n但见：\n",me);
//  message_vision (this_object()->query("long"),me);
        me->set_temp("fire_huoba",1);
        remove_call_out ("precreate");
        call_out ("precreate",20,this_object());
        destruct(present(arg,me));
        return 1;
}

void precreate (object me)
{
        tell_room (me,"光线忽的一暗，火把熄灭了，四周又变得一片漆黑！\n\n");
        me->delete_temp("fire_huoba");
        me->create();
//      destruct(present("huo ba",me));
}

int do_insert (string arg)
{
        object ob;
        object me = this_player();
        if ((int)me->query_temp("fire_huoba")< 1)
             return notify_fail("四周黑漆漆的，什么也看不见啊？\n");
        if (arg != "tongpai")
             return 0;
        if (!present(arg,me))  return notify_fail("你要插入什么？\n");
        if ((int)me->query_temp("fire_huoba")< 1)
             return notify_fail("四周黑漆漆的，什么也看不见啊？\n");
        message_vision ("$N试着将铜牌插入石壁上的小孔中！\n\n",me);
        message_vision (HIC"忽然一阵隆隆的剧烈震动，$N只觉得一阵天旋地转！\n\n"NOR,me);
        destruct(present(arg,me));
        ob = load_object(__DIR__"mishi");
        ob = find_object(__DIR__"mishi");
        message("vision", me->query("name")+"忽然从室顶缝隙中滑了进来。\n", ob);
        message_vision ("$N忽然觉得脚下一空，竟掉了下去！\n\n",me);
        me->delete_temp("fire_huoba");
        me->move(__DIR__"mishi");
        return 1;
}
int do_climb(string arg)
{
        object me=this_player();
        object ob;
        if( (!arg) ||!((arg == "岩壁") || (arg == "洞壁")))
                return notify_fail("你要爬什么？\n");
        message_vision(HIC"$N小心翼翼的攀着岩壁上突出的石笋爬了下去。\n\n"NOR,me);
        ob = load_object(__DIR__"wandu3");
        ob = find_object(__DIR__"wandu3");
        message("vision", me->query("name")+"从岩壁上爬了下来。\n", ob);
        me->move(__DIR__"wandu3");
        return 1;
}

void recreate ()
{
        set ("short", "洞穴");
        set ("long", @LONG
这是一个狭窄的洞穴，四周石壁湿漉漉的，长满了青苔。你仔细
观察一下四周的情况，发现洞内深处有一块石壁非常平整，象是有人
力的痕迹，正中间有一个扁扁的小孔，好象可以插入(insert)什么东
西试试。
LONG);

        set("exits", ([
//        "down"  : __DIR__"wandu3",
        ]));
//      set("outdoors","wudujiao");

        set("coor/x", -44970);
	set("coor/y", -81120);
	set("coor/z", 10);
	setup();
}

