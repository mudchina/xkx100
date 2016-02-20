// /quest/wei.c
// Modified by Zeratul Jan 5 2001
// Modified by Sir 5/17/2001 
// 10个任务一轮,奖励累加,增加两个任务之间的时间限制，恢复用钱取消的功能
// 500个一轮，奖励根据完成数增加
inherit NPC;
//inherit F_SKILL;
#include <ansi.h>
#include <quest.h>
#define GIFT_DIR "/clone/gift/"

private void special_bonus(object me, object who);
string time_period(int timep,object me);
int do_answer(string arg);
int do_cancel();
int do_fangqi();
string do_gonglao();
#define MAX_BAOWU_EXP 1000000
#define MAX_NEED 1000000  //100gold取消

void create()
{
  set_name("韦小宝", ({ "wei xiaobao", "wei", "xiaobao" }));
  set("title", HIC"大清国抚远大将军"HIY"一等鹿鼎公"NOR);
  set("nickname", HIW"小白龙"NOR);
  set("gender", "男性");
  set("age", 18);
  set("str", 20);
  set("int", 30);
  set("con", 30);
  set("dex", 20);
  set("per", 28);
  set("long", 
"这位少年将军头戴红顶子，身穿黄马褂，眉花眼笑，贼忒兮
兮，左手轻摇羽扇，宛若诸葛之亮，右手倒拖大刀，俨然关
云之长，正乃韦公小宝是也。见你看着他，“哈哈哈”，仰
天大笑三声，学足了戏文中曹操的模样，你顿时忍不住凑个
趣，问一句：“将军为何发笑？”\n");
  set("combat_exp", 50000);
  set("shen_type", 1);
  set("attitude", "peaceful");
  set("max_qi", 2500);
  set("max_jing", 1000);
  set("neili", 500);
  set("max_neili", 500);
  set("jiali", 50);

  set_skill("force", 20);
  set_skill("parry", 20);
  set_skill("hand", 20);
  set_skill("dodge", 20);
  set_skill("shenxing-baibian", 20);
  set_skill("yunlong-shengong", 20);
  set_skill("qianye-shou", 90);

  map_skill("force", "yunlong-shengong");
  map_skill("parry", "qianye-shou");
  map_skill("dodge", "shenxing-baibian");
  map_skill("hand", "qianye-shou");
  prepare_skill("hand", "qianye-shou");
  set("inquiry", ([
      "天地会" : "别烦我！\n",
      "陈近南" : "那是我师父！\n",
      "茅十八" : "就是那十八个毛虫啊？他还没死吧！\n",
      "独臂神尼": "那是我美貌尼姑师父！\n",
      "韦春芳" : "我娘做婊子生意越来越差了，现在改行作老鸨了！\n",
      "康熙"   : "那是我皇帝师父！\n",
      "小玄子" : "那是我皇帝师父！\n",
      "小桂子" : "别提这个名字了，我怕怕！\n",
      "阿珂"   : "她是我明媒正娶的大老婆！\n",
      "双儿"   : "你认识她？大功告成，亲个嘴儿！\n",
      "曾柔"   : "我老婆你问那么多干嘛？皇上洪福齐天，我艳福齐天！\n",
      "方怡"   : "我老婆你问那么多干嘛？皇上洪福齐天，我艳福齐天！\n",
      "苏荃"   : "我老婆你问那么多干嘛？皇上洪福齐天，我艳福齐天！\n",
      "沐剑屏" : "我老婆你问那么多干嘛？皇上洪福齐天，我艳福齐天！\n",
      "建宁公主" : "这个骚娘皮，亲厚不及双儿、美貌不及阿珂、武功不及苏荃、机巧不及方怡、天真纯善不及沐剑屏、温柔斯文不及曾柔，差有一日之长者，不过横蛮泼辣而已！\n",
      "取消任务":  (: do_cancel :),
      "cancel" :   (: do_cancel :),
      "功劳"   :   (: do_gonglao :),
      "gonglao":   (: do_gonglao :),
//      "放弃"：  (:do_fangqi:),
//      "fangqi": (:do_fangqi:),
  ]) );

  setup();
  carry_object(CLOTH_DIR"jinduan")->wear();
}

void init()
{
  object ob;

  ::init();
  add_action("give_quest", "quest");
  add_action("do_answer","answer");
}
int do_cancel()
{ 
  object who=this_player();
  if (who->query("quest/wei/finished")==1)
  {
    tell_object(who,"韦小宝笑道：你没有领任务啊，有什么好取消的。\n");
    return 1;
  }
  if (who->query("balance")<1000000)
  {
    tell_object(who,"韦小宝笑道：你就这点微薄家产，还是好好找一下我要的东西吧。\n");
    return 1;
  }
  who->add("balance",-1000000); 
  tell_object(who,"韦小宝笑道：好好，我就收你一些黄金做为补偿。你也不用再辛苦了，下去休息休息吧。\n");
  who->set("quest/wei/finished",1);
  who->delete( "quest/wei/time" );
  return 1;
}
string do_gonglao()
{
  if (this_player()->query("quest_num/wei"))
  return "你已经连续帮我收集到"+chinese_number(this_player()->query("quest_num/wei"))+"样东西了。";
  else
  return "你没有帮我做过什么事情啊。";
}

int do_fangqi()
{
  object who=this_player();
  return 0; 
}
int do_answer(string arg)
{
  object me=this_player();
  object ob;
  string un;
  int meili,gift,type;
  
  if (!me->query_temp("quest_gift/got"))
    return 0;
  if (arg=="Y" || arg=="y" || arg=="yes")
    type=1;
  else if (arg=="N" || arg=="n" || arg=="no")
    type=2;
  else return notify_fail("你要回答什么？\n");
    if (living(me) && living(this_object()) && type==1)
    {
        me->delete_temp("quest_gift/got");
        if (me->query("meili")<me->query_temp("quest_gift/meili")+60)
          return notify_fail("你就这么点魅力，也好意思问韦爵爷要东西？\n");
      message_vision(CYN "\n$N" CYN "急忙点点头，说道：这东西正好我也需要，就交给我吧。\n" NOR, me);
      arg=me->query_temp("quest_gift/obj");
      ob = new(arg);
      if (!ob) 
        return notify_fail("韦小宝纳闷道：咦？我的东西呢？刚才还在，怎么转眼就没了。\n");
      if (ob->query("base_unit"))
         un = ob->query("base_unit");
      else
         un = ob->query("unit");
      me->add("meili", - me->query_temp("quest_gift/meili"));
      message_vision("韦小宝微微一笑，拿出一" + un + ob->name() + NOR "交给$N。\n" NOR,me);
      ob->move(me);
      log_file("gift/wei_give",sprintf("[%s]give %8s %20s \n",ctime(time()),me->query("id"),base_name(ob)));
    }
    else if (living(me) && living(this_object()) && type==2)
      {
        me->delete_temp("quest_gift/got");
        tell_object(me,HIW"韦小宝叹气道：也罢，既然你不需要，这东西我"
                                       "就留给别人吧。\n"NOR);
      }
      return 1;
}

int give_quest()
{
  mapping quest;
  object me = this_player();
  int combatexp, timep, factor;
  int num;

  combatexp = (int) (me->query("combat_exp"));
  if(combatexp<1000)
  {
    tell_object(me,"韦小宝对你哼了一声道：“辣块妈妈，东西还没长齐想干嘛？”\n");
    return 1;
  }
/*  if(combatexp>10000000)
  {
    tell_object(me,"韦小宝对你哼了一声道：“辣块妈妈，花差大爷我忙着呢，没空理你！”\n");
    return 1;
  }
*/  if (me->query("meili") < 0 || me->query("weiwang") < 0)
  {
    tell_object(me,"韦小宝对你哼了一声道：“你是个什么东西，也来这里捣乱。\n");
    return 1;
  }
  if (me->query("combat_exp") <= me->query("quest/wei/busy_exp"))
  {
    tell_object(me,"韦小宝对你说道：我暂时不需要你帮忙，你先去其它地方历练一下再来。\n");
    return 1;
  }
  if (me->query_temp("quest_gift/got"))
  {
     tell_object(me,"韦小宝对你说道：我正问你话呢，你快点回答(answer y|n)啊。\n");
      return 1;
    }
// Let's see if this player still carries an un-expired task
  if( me->query("quest/wei/quest") && !me->query( "quest/wei/finished" ) )
  {
    if( ((int) me->query("quest/wei/time")) > time() )
    {
      tell_object(me,"韦小宝对你笑道：说你不行吧，还不服气？\n");
      return 1;
    }
    else
    {
      tell_object(me,"韦小宝对着你叹了一口气：没关系去拿别的也成。\n");
//      me->add("qi",-(int)(me->query("qi")/5));
//      quest_failed( me, "wei" );

//      tell_object(me,HIW"韦小宝对你说道：不是让你去拿『"+me->query("quest/wei/quest")+HIW+"』吗？时间已经过了，我要的东西呢。\n"NOR);
//      return 1;
    }
  }
  else
//    if ( me->query("/quest/wei/time") + 90 + random(60) > time())   
      if ( me->query("/quest/wei/time") + 2 > time())   
    {
      tell_object(me,"韦小宝对你微微一笑道：你过于劳累，歇息会儿再上路吧。\n");
      return 1;
    }

//  factor=10;
    if(!me->query("quest_num/wei") || 
    (int)me->query("quest_num/wei")<0 ||
    (int)me->query("quest_num/wei")>500)
      me->set("quest_num/wei",1); //给人物第quest_num/wei个任务

  num=me->query("quest_num/wei");
  if(num <= 5)
    quest = __DIR__"qwlist1"->query_quest("easy_quest");
  else if ( num%50 == 0)
  {
    quest = __DIR__"qwlist1"->query_quest("hard_quest");
    tell_object(me,"韦小宝微微一笑：做得不错嘛，看来我可以托付你个难一些的任务。\n");
  } 
  else
    quest = __DIR__"qwlist1"->query_quest("normal_quest");
  timep = random(10) * 60 + 15*60;
  
  tell_object(me,HIW "韦小宝吩咐道：给你在" + time_period(timep, me) + "内");
  tell_object(me,"找到『"+quest["quest"]+HIW"』给我，我会好好谢你。\n" NOR);

  quest["quest_type"] = "寻";
//  quest["exp_bonus"] = 10 + random(10);
//  quest["pot_bonus"] = 2 + random(4);
//  quest["score"] = 2 + random(4);

  me->set("quest/wei/quest", quest["quest"]);
  me->set("quest/wei/time", (int)time()+timep);
//  me->set("quest/wei/factor",factor);
  me->set( "quest/wei/finished",0 );
  me->set("quest/wei/quest_type",quest["quest_type"]);
  me->delete("quest/wei/busy_exp");
//  if(!me->query_temp("wei_quest_num") ||
//    (int)me->query_temp("wei_quest_num")==10)
//    me->set_temp("wei_quest_num",1);
//  if ((int)me->query_temp("wei_quest_num")<0) 
//    me->set_temp("wei_quest_num",1);
//add by sega 4/11/2000
//  me->set("last_quest_time",(int)time());
//  me->add("quests/require", 1);
  return 1;
}

string time_period(int timep, object me)
{
  int t, d, h, m, s;
  string time;
  t = timep;
  s = t % 60; t /= 60;
  m = t % 60; t /= 60;
  h = t % 24; t /= 24;
  d = t;

  if(d) time = chinese_number(d) + "天";
  else time = "";

  if(h) time += chinese_number(h) + "小时";
  if(m) time += chinese_number(m) + "分";
  time += chinese_number(s) + "秒";

  return time;
}

int accept_object(object who, object ob)
{
  int exp, pot, score, num,level, myexp;
  mapping quest;
  object gift;
  int need;

  if (ob->query("id") == "bao wu")
  {
    if (who->query_temp("baowunum") < 0)    
            return notify_fail("去去去，哪儿找的假货，想来蒙韦爵爷我？！\n");               
    if (ob->query("owner") != who->query("id") )
    {
      tell_object(who,HIW"韦小宝高兴地说，我正想要" + ob->query("name")+ HIW"呢，多谢你把别人的宝物转送给我。\n"NOR);
    }
    else
    {
      exp = 10 + random(10);
      pot = 7 + random(5);
      score= 5 + random(10);
      who->add("score",score);
      who->add_temp("baowunum",-1);
      who->add("marks/baowu",1);
      tell_object(who,HIW"韦小宝高兴地说，我正想要" + ob->query("name")+ HIW"呢，蒙你见爱，我也送你些东西吧。\n");
     if ((who->query("combat_exp") < MAX_BAOWU_EXP)  || who->query_temp("invite"))
      {
        who->add("combat_exp",exp);
        who->add("potential", pot);
        tell_object(who,"（"+ chinese_number(exp) + "点经验，" + chinese_number(pot) + "点潜能，"+ chinese_number(score) + "点江湖阅历。)\n"NOR);
		  }
		  else 
		  {
		  	exp = exp/2;
		  	pot = 1;
        who->add("combat_exp",exp);
        who->add("potential", pot);
        tell_object(who,"（"+ chinese_number(exp) + "点经验，" + chinese_number(pot) + "点潜能，"+ chinese_number(score) + "点江湖阅历。)\n"NOR);
    	}
    }
    return 1;
  }
  if ( ob->query("money_id") )
  {
  	need = 10000;
  	myexp = who->query("combat_exp");
  	if (myexp <= 100000 ) need = 1000; // 10 silver 
  	else if (100000 <= myexp && myexp <= 500000) need = 3000; // 30 silver
  	else if (500000 <= myexp && myexp <= 1000000) need = 5000; // 50 gold
  	else if (100000 <= myexp && myexp <= 2000000) need = 10000; // 1 gold
  	else if (200000 <= myexp && myexp <= 3000000) need = 20000; // 2 gold
  	else if (300000 <= myexp && myexp <= 4000000) need = 30000; // 3 gold
  	else if (400000 <= myexp && myexp <= 5000000) need = 40000; // 4 gold
  	else need = 50000; // 5 gold
    if ( !who->query("quest/wei/quest") ||
      who->query("quest/wei/finished") ||
      ob->value() < need )
      tell_object(who,"韦小宝笑道：那我可就不客气了。\n");
    else if (ob->value()>=MAX_NEED)
    {
      who->set("quest/wei/finished",1);
      tell_object(who,"韦小宝笑道：好好，看你这么有诚意。你也不用再辛苦了，下去休息休息吧。\n");
      who->delete( "quest/wei/time" );
      }
    else
    {
      tell_object(who, "韦小宝叹了口气说道：那好，咱们买卖不成仁义在。想要好处再找我吧！\n");
      if(random(20)==1 && who->query("combat_exp") > 150000) 
        {
        tell_object(who,HIR"由于你经常完不成任务，韦小宝开始不信任你了。\n"NOR);
        who->add("weiwang",-10);
        who->set("quest/wei/busy_exp",who->query("combat_exp")+300);
        if (who->query("meili")>100)
        who->add("meili",(int)-query("meili")/3);
        else
        who->add("meili",-25);
        }
      who->set( "quest/wei/finished", 1 );
      who->set( "quest/wei/time" ,time()+10);
      who->delete("quest_num/wei");
    }
    return 1;
  }
  
  if (  (!quest = who->query( "quest/wei/quest" ))  ||
    who->query( "quest/wei/finished" ) )
  {
    tell_object( who,"韦小宝说道：你给我这个干嘛？\n" );
    return 0;
  }
  if( ob->query("name") != quest || ob->is_character() )
  {
    tell_object(who, "韦小宝说道：这是什么东西？我叫你办的事你就这样糊弄我？！\n");
    return 0;
  }
  if ((int) who->query("quest/wei/time") <= time() )
  {
    tell_object(who,"韦小宝说道：你是怎么搞得，现在才把东西弄来！这次就算了，以后要注意。\n");
//    quest_failed( who, "wei" );
    who->delete("quest/wei/quest");
//    who->delete("quest_num/wei");
//    quest_finished( who, "wei" );
    who->delete("quest/wei/finished");
//    who->delete("")
//    destruct(ob);
    ob->set("id","bao wu");//让give.c把物品dest
    return 1;
  }
  else
  {
    tell_object(who,"韦小宝赞许地点头说道：不错！差使办得不错！\n");
    who->set("quest/wei/finished",1);

    num = (int)who->query("quest_num/wei");
    if (num >= 450) level=9;
    else if (num >= 400) level=8;
    else if (num >= 200) level=7;
    else if (num >= 100) level=6;
    else if (num >= 50) level=5;    
    else if (num >= 20) level=4;
    else if (num >= 6) level=3;
    else level=0;
    if (who->query("combat_exp")<200000 && level<1) level=1;
    if (level>=10) level=10;
    exp = 60* level + random(30)+3;
    exp=exp*2/3+random(exp*2/3);
    pot = 18* level + random(9)+1; 
    pot=pot*2/3+random(pot*2/3);
    score = 20 + 20* level + random(10);
    who->add("combat_exp", exp);
    who->add("potential", pot);
    who->add("score", score);
	who->set_temp("prize_reason","小宝");
	who->set_temp("can_give_prize",1);
	who->set_temp("prize_exp",exp);
	who->set_temp("prize_pot",pot);
    tell_object(who,HIW"经过一番辛苦奔波，你增长了：" + chinese_number(exp) + "点实战经验，"+ chinese_number(pot) + "点潜能，" + chinese_number(score)+"点江湖阅历。\n"NOR);
    tell_object(who,HIW"恭喜你完成第"+chinese_number(who->query("quest_num/wei"))+"个差使！\n"NOR);   

    who->delete("quest/wei/busy_exp");
    if (num>49 && num<501 && num%50==0 ) 
      special_bonus(this_object(),who);  //整五十做特殊物品奖励

    who->add("quest_num/wei",1);
    who->add("quest_num/allwei",1);
    
    if (who->query("skybook/luding/passed")) who->add("meili",2);
    //完成四十二章经任务 奖励魅力多一些
    else who->add("meili",1);
    
    who->set("quest/wei/time", (int)time());
    if (num>30 && random(100)==1)
    {
    who->set("quest/wei/busy_exp",who->query("combat_exp")+1000);
    gift=new("/clone/money/gold");
    gift->set_amount(50);
    message_vision("$N笑道：这位"+RANK_D->query_respect(who)+"实在是我的得力助手，这里有些黄金你先拿着。下去好好歇息歇息，别累坏了身子。\n" NOR,this_object()); 
    gift->move(this_object());
    command("give 50 gold to "+who->query("id"));
    }
    destruct(ob);
    return 1;
  }
  return 1;
}

//物品奖励
void special_bonus(object me, object who)
{
        int cost;
        string need;

        // 五十奖励
        string *ob1_list = ({//珠宝
                "clone/jewelry/biyu",
                "clone/jewelry/feicui",
                "clone/jewelry/goldring",
                "clone/jewelry/maoeryan",
                "clone/jewelry/necklace",
                "clone/jewelry/shanhu",
                "clone/jewelry/yubei",
                "clone/jewelry/yudai",
        });

        // 完成一百个任务
        string *ob2_list = ({//伤药
          "/clone/medicine/nostrum/baihudan",
          "/clone/medicine/nostrum/baiyunwan",
          "/clone/medicine/nostrum/huiyangsan",
          "/clone/medicine/nostrum/jiuhuawan",
          "/clone/medicine/nostrum/shenyangjiu",
          "/clone/medicine/nostrum/tianxianggao",
        });

        // 完成一百五十个任务
        string *ob3_list = ({//初级内力补药
           "/clone/medicine/nostrum/xiongdan",
           "/clone/medicine/nostrum/guaishedan",
           "/clone/medicine/nostrum/guaishexue",
           "/clone/medicine/nostrum/huochan",
          GIFT_DIR+"gift/con1",
          GIFT_DIR+"gift/str1",
   //       GIFT_DIR+"gift/int1",
          GIFT_DIR+"gift/dex1",
        });

        // 完成二百个任务
        string *ob4_list = ({//低级武功药
          GIFT_DIR+"pill/renshen1",
          GIFT_DIR+"pill/lingzhi1",
          GIFT_DIR+"pill/xuelian1",
          GIFT_DIR+"pill/shouwu1",
        });

        // 完成二百五十个任务
        string *ob5_list = ({//高级内力补药
           "/clone/medicine/nostrum/labazhou",
           "/clone/medicine/nostrum/renshenguo", 
           "/clone/medicine/nostrum/binghuojiu",
        });

        // 完成三百个任务
        string *ob6_list = ({//中级武功药
           "/clone/medicine/nostrum/puti-zi",
          GIFT_DIR+"pill/renshen2",
          GIFT_DIR+"pill/lingzhi2",
          GIFT_DIR+"pill/xuelian2",
          GIFT_DIR+"pill/shouwu2",
        });

        // 完成三百五十个任务
        string *ob7_list = ({//中级天赋药
          GIFT_DIR+"gift/con2",
          GIFT_DIR+"gift/str2",
     //     GIFT_DIR+"gift/int2",
          GIFT_DIR+"gift/dex2",
        });

        // 完成四百个任务
        string *ob8_list = ({//高级武功药
          GIFT_DIR+"pill/renshen3",
          GIFT_DIR+"pill/lingzhi3",
          GIFT_DIR+"pill/xuelian3",
          GIFT_DIR+"pill/shouwu3",
        });

        // 完成四百五十个任务
        string *ob9_list = ({//加福缘耐力灵性等的丹药
          GIFT_DIR+"gift/kar",
          GIFT_DIR+"gift/spi",
          GIFT_DIR+"gift/sta",
          GIFT_DIR+"gift/per",
          GIFT_DIR+"gift/cps",
          GIFT_DIR+"gift/cor",
        });

        // 完成五百个任务
        string *ob10_list = ({//加臂力根骨身法悟性的丹药
          GIFT_DIR+"gift/str3",
          GIFT_DIR+"gift/con3",
          GIFT_DIR+"gift/dex3",
       //   GIFT_DIR+"gift/int3",
        });


        string un, gift;
        object ob;


        if (who->query("quest_num/wei") == 500)
        {
                gift = ob10_list[random(sizeof(ob10_list))];
                cost = 200;
        } else

        if (who->query("quest_num/wei") == 450)
        {
                gift = ob9_list[random(sizeof(ob9_list))];
                cost = 200;
        } else

        if (who->query("quest_num/wei") == 400)
        {
                gift = ob8_list[random(sizeof(ob8_list))];
                cost = 150;
        } else

        if (who->query("quest_num/wei") == 350)
        {
                gift = ob7_list[random(sizeof(ob7_list))];
                cost = 150;
        } else

        if (who->query("quest_num/wei") == 300)
        {
                gift = ob6_list[random(sizeof(ob6_list))];
                cost = 100;
        } else

        if (who->query("quest_num/wei") == 250)
        {
                gift = ob5_list[random(sizeof(ob5_list))];
                cost = 100;
        } else

        if (who->query("quest_num/wei") == 200)
        {
                gift = ob4_list[random(sizeof(ob4_list))];
                cost = 70;
        } else

        if (who->query("quest_num/wei") == 150)
        {
                gift = ob3_list[random(sizeof(ob3_list))];
                cost = 40;
        } else

        if (who->query("quest_num/wei") == 100)
        {
                gift = ob2_list[random(sizeof(ob2_list))];
                cost = 10;
        } else

        if (who->query("quest_num/wei") == 50)
        {
                gift = ob1_list[random(sizeof(ob1_list))];
                cost = 5;
        } 
        else
        {
                return;
        }
        ob = new(gift);

        if (ob->query("base_unit"))
                un = ob->query("base_unit");
        else
                un = ob->query("unit");

        if (who->query("meili") >= cost+60)
        {
                message_vision(CYN "$n" CYN "对$N" CYN "微笑道：我这里刚刚得到一"
                               + un + ob->name() + CYN "，你要的话，送你也无妨。\n" NOR, who, me);

                if (base_name(me)=="/quest/weixiaobao") need = "江湖魅力";
                else need = "门派贡献";
                tell_object(who, HIW "\n获得" + ob->name() + HIW "会降低"
                                 "你" + chinese_number(cost) + "点"+need+
                                 "，你可以选择回答(answer Y|N)是或者否。\n" NOR);

                // 记录可以领取奖励
                who->set_temp("quest_gift/got", 1);

                // 记录任务奖励物品的路径
                who->set_temp("quest_gift/obj", gift);

                // 记录领取该物品所需的门牌贡献
                who->set_temp("quest_gift/meili", cost);
        } 
        else 
        {                message_vision(CYN "$n" CYN "对$N" CYN "微笑道：我刚刚拿到。。"+
        "嗯，算了，想来你也用不着。\n" NOR, who, me);}
        destruct(ob);
}