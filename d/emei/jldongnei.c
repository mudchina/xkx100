//Room: jldongnei.c 九老洞
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","九老洞");
      set("long",@LONG
这就是峨嵋第一大洞，洞内深窈无比，神秘难测。你一走进来，便发觉洞
中叉叉洞多如迷宫，怪异莫测，似乎黝黑无底。洞里隐隐传来鸡犬鼓乐之声，
令人惊异间，忽有蝙蝠群涌而至，扑熄火炬。还是快快离开吧。
LONG);
      set("objects", ([
           __DIR__"npc/poorman" : 2,
           __DIR__"npc/little_monkey" : 3,
           __DIR__"npc/bat" : 4,
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6170);
	set("coor/y", -1100);
	set("coor/z", 100);
	setup();
}
void init()
{
        add_action("do_leave", "leave");
}

int do_leave(string arg)
{
        object me;
        object *inv;
	int i;
        me = this_player();
        inv = all_inventory(environment(me));
        for (i = 0; i < sizeof(inv); i++)
        {
          if (inv[i]->is_character())
             {
              inv[i]->move(__DIR__"jiulaodong");
             }
        } 
//        me->move(__DIR__"jiulaodong");
        return 1;
}