//Room: jldongkou.c 九老洞口
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","九老洞口");
      set("long",@LONG
九老洞在仙峰寺外。传说远古时候，有九位仙叟住在这个洞里，不知他们
生于何年，终于何年。轩辕皇帝访道于此，见一老叟，问曰：『有侣乎？』答
曰：『九人』。这就是九老洞的来历。这个洞很深，很少有人进去，只有些人
站在洞口谈笑呼叫（yell）。这里向西经九十九道拐到千佛庵，一路向北到莲
花石。
LONG);
      set("objects", ([
           __DIR__"npc/little_monkey" : 2,
      ]));
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "enter"     : __DIR__"jiulaodong",
          "northwest" : __DIR__"lianhuashi",
          "northeast" : __DIR__"jsjdg4",
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6180);
	set("coor/y", -1090);
	set("coor/z", 100);
	setup();
}

void init()
{
        add_action("do_yell", "yell");
}

int do_yell(string arg)
{
        object me;

        me = this_player();
        message_vision("$N站在洞口向里大叫：“0”\n", me);
        write("洞内传来一阵回声：“0～～～0～～～0～～～”\n");
        return 1;
}