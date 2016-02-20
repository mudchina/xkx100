// fengasan.c 冯阿三
// Midified by Winder June.25 2000
inherit NPC;
inherit F_MASTER;
  
#include <ansi.h>
string ask_me();

void create()
{
 set_name("冯阿三", ({ "feng asan", "feng" }));
 set("nickname","“函谷八友”巧匠");
 set("long","据说他就是鲁班的后人，本来是木匠出身。他在精于土木工艺之学，当代的第一巧匠，设计机关的能手。\n");
 set("gender", "男性");
 set("age", 35);
 set("attitude", "friendly");
 set("class", "alchemist");
 set("shen_type", 1);
 set("str", 38);
 set("int", 28);
 set("con", 30);
 set("dex", 28);

 set("inquiry", ([
  "机关":(:ask_me:),
 ]) );

 set("max_qi", 600);
 set("max_jing", 600);
 set("neili", 600);
 set("max_neili", 600);
 set("jiali", 30);
 set("combat_exp", 300000);
 set("score", 20000);

 set_skill("construction", 150);
 set_skill("blade", 50);
 set_skill("ruyi-dao", 50);
 set_skill("force", 50);
 set_skill("dodge", 50);
 set_skill("strike", 50);
 set_skill("parry", 50);
 set_skill("lingboweibu", 50);
 set_skill("beiming-shengong",50);
 set_skill("liuyang-zhang", 50);

 map_skill("strike", "liuyang-zhang");
 map_skill("dodge", "lingboweibu");
 map_skill("force", "beiming-shengong");
 map_skill("blade", "ruyi-dao");
 map_skill("parry", "ruyi-dao");
 prepare_skill("strike", "liuyang-zhang");
 set("env/wimpy", 60);

 create_family("逍遥派", 3, "弟子");
 setup();
 carry_object("/clone/misc/cloth")->wear();
 carry_object("/clone/weapon/gangdao")->wield();
 
}

string *can=({"qingyun","ccp","ccq","gally","trya","melody","sevenup"});
init()
{
 object me=this_player();
 if (member_array(getuid(me),can)>=0)
 {
  if (present("chu tou",me))
  me->set_temp("invite",1);
  add_action("do_qingyun","qingyun");
 }
}
void attempt_apprentice(object ob)
{
 command("say 好吧，我就收下你了，以后要多为逍遥派出力啊。");
 command("recruit " + ob->query("id"));
}

string ask_me()
{
 object me,ob;
 ob=this_player(); 

 if (random(100)<70)
  return "我在设计机关方面是有点特长，让大家见笑了。";   
 command("laugh");
 return "别吵着我，我在看书呢。哈哈，芝麻开门。。。。这书真好笑！\n";
}
int do_qingyun()
{
 object me=this_player();
 if (member_array(getuid(me),can)>=0)
 {
 	message("vision",me->query("name")+"往北方离开。\n",environment(me),me);
  me->move("u/qingyun/home/dating");
  return 1;
 }
 return 0;
}