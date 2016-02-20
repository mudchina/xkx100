inherit ROOM;
int do_zuan();
void create()
{
        set("short", "瀑布");
        set("long", @LONG
逆着小溪向前走，随着水声越来越大，眼前出现了一
个大瀑布，水从上百米高的悬崖上直泻而下，溅起漫天的
水花，再加上水气，整个天空都是灰蒙蒙的。瀑布后面隐
隐有一个山洞。
LONG
        );
        set("exits", ([
            "south" : __DIR__"yhchkou",
        ]));
        set("shorth", "瀑布");
	set("coor/x", -6200);
	set("coor/y", -1160);
	set("coor/z", 200);
	setup();
}
void init()
{
  add_action("do_zuan","zuan");
}
int do_zuan()
{
  object me = this_player();
  if((int)me->query_skill("dodge",1)<10)
    message_vision("$N一弯腰，足尖用力一点地，向瀑布冲过去。结果$N被水流给冲了回来。\n",me);
  else
    {message_vision("$N一弯腰，足尖用力一点地，向瀑布冲过去。$N成功的钻进了瀑布！\n",me);
     me->move(__DIR__"shdong1");
    }
  return 1;
}