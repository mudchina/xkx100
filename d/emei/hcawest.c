//Room: hcawest.c 华藏庵侧殿
//Date: Oct. 2 1997 by That

inherit ROOM;
string look_chuang();
string look_paizi();

void create()
{
      set("short","华藏庵侧殿");
      set("long",@LONG
这里是金顶华藏庵西侧殿，是接待香客及来宾的地方。殿内摆着几张桌子，
桌旁围放数把椅子。墙上悬着几幅字画，墙边一排书架，架上摆满经书。有几
位进香客正在品茶养神，欣赏墙上的字画或翻阅架上的经书。还有两个二十来
岁的姑娘在向一位师太打听有关出家的事。一个十来岁的小师太正在忙前忙后
招待客人。南边有扇窗子(chuang)。
LONG);
      set("objects", ([
           CLASS_D("emei") + "/wenqing" : 1,
      ]));
      set("item_desc", ([
          "chuang" : (: look_chuang :),
          "paizi"  : (: look_paizi :),
      ]));
      set("exits",([ /* sizeof() == 1 */
          "east"   : __DIR__"hcazhengdian", 
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6210);
	set("coor/y", -1160);
	set("coor/z", 190);
	setup();
}

string look_chuang()
{
    return "窗外可以看到峨嵋山的秀丽山景。窗下有个小牌子(paizi)。\n";
}
string look_paizi()
{
    return "牌子上写着：请来客行为尊重，切勿跳(jump)窗。\n";
}
void init()
{
        add_action("do_jump", "jump");
}
int do_jump(string arg)
{
        object me;
        if (!arg ||arg !="chuang") return 1;
        me = this_player();
        message_vision("$N趁人不注意，跳出窗外。\n",me);
        me->move(__DIR__"xiaoshulin1");
        message_vision("$N从华藏庵里跳窗出来。\n",me);
        return 1;
}