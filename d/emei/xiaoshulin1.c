//Room: xiaoshulin1.c 小树林
//Date: Oct. 2 1997 by That

inherit ROOM;
void create()
{
      set("short","小树林");
      set("long",@LONG
这是峨嵋山金顶华藏庵外的一片小树林。林中没有路，但地上依稀有些足
迹，似乎刚有人走过。北面有一扇小窗。
LONG);
      set("outdoors", "emei");
      set("exits",([ /* sizeof() == 1 */
          "south"   : __DIR__"xiaoshulin2", 
      ]));
      set("no_clean_up", 0);
	set("coor/x", -6210);
	set("coor/y", -1180);
	set("coor/z", 180);
	setup();
}

void init()
{
      add_action("do_jump", "jump");
}
int do_jump(string arg)
{
      object me;
      if (!arg || arg !="chuang") return 1;
      me = this_player();
      message_vision("$N趁人不注意，跳进窗里。。\n",me);
      me->move(__DIR__"hcawest");
      message_vision("$N从华藏庵外跳窗进来。\n",me);
      return 1;
}