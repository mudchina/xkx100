// xiaoheshang.c

inherit NPC;

void init();
int ask_dingli();
int ask_changli();
void greeting(object ob);
void serve_tea(object who);

void create()
{
      set_name("小和尚", ({ "xiao heshang" }) );
      set("gender", "男性" );
      set("age", 14);
      set("long", "这是个机灵乖巧的小和尚\n");
      set("str", 15);
      set("dex", 20);
      set("con", 17);
      set("int", 15);
      set("shen_type", 1);

      set_skill("unarmed", 50);
      set_skill("dodge", 35);
      set_temp("apply/attack", 5);
      set_temp("apply/defense", 5);
      set("combat_exp", 7500);
      set("startroom","/u/solomon/workroom");

      set("attitude", "peaceful");
      set("inquiry", ([
            "定力" : (: ask_dingli :),
            "禅力" : (: ask_changli :),
            "天马行空" : "你玩完啦，居然连我的主人都不认识！\n",
      ]));
      set("chat_chance", 20);
      set("chat_msg", ({
            "南无阿弥陀佛！\n",
            "南无弥勒佛菩萨！\n",
            "南无大势致菩萨！\n",
            "南无大慈大悲观世音菩萨！\n",
            (: random_move :),
            (: random_move :),
      }) );
                      
      setup();
}

void init()
{
      object ob;

      ::init();

      if ( interactive(ob = this_player()) && !is_fighting() )
      {
             remove_call_out("greeting");
             call_out("greeting", 1, ob);
      }
}

void greeting(object ob)
{
      if ( environment(ob) != environment() )
            return;
      if (ob->query("id") == "solomon" )
            command("say 师傅回来啦");
      else
            command("hi "+ob->query("id"));
}

int ask_dingli()
{
      if ( this_player()->query("chanxin/save")>=2 )
      {
            command("say 这个麽你还是有一点的！\n");
            this_player()->set("chanxin/save",3);
      }
      else
      {
            command("say 别给我打哈哈，瞧你这德性！\n");
      }
      return 1;
}

int ask_changli()
{
      if ( this_player()->query("chanxin/save")>=3 )
      {
            command("say 这个麽还不错，要到楼上来喝点酒么！\n");
            this_player()->set("chanxin/save",4);
      }
      else
      {
            command("say 别给我打哈哈，瞧你这德性！\n");
      }
      return 1;
}

void serve_tea(object who)
{
      object obt, obc, obn;
      object room;

      if ( !who || environment(who) != environment() )
            return;

      if( !who->query_temp("marks/sit") )
            return;
      
      if( !objectp(room = environment()) )
            return;

      obn = new("d/wudang/obj/xiangcha");
      obn->move(room);
      message_vision("小和尚拿出紫沙小茶壶，沏了杯香茶，放在桌上．\n", who);

      obn = new("d/hangzhou/npc/obj/jiuping");
      obn->move(room);
      obn = new("d/hangzhou/npc/obj/pork");
      obn->move(room);
      obn = new("d/hangzhou/npc/obj/geng");
      obn->move(room);
      obn = new("d/hangzhou/npc/obj/shrimp");
      obn->move(room);
      obn = new("d/hangzhou/npc/obj/chicken");
      obn->move(room);
      obn = new("d/hangzhou/npc/obj/fish");
      obn->move(room);
      message_vision("然后拿出一瓶酒和一盘盘好吃的放在桌上．\n", who);
      
      return;
}
