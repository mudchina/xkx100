//需配合dream-blade,易水楼之二skill
//edit by Trf
#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit F_SSERVER;
//inherit F_FUNCTION;
void seven(object me,object victim,object weapon,int damage);
void lockman(object me,object victim,object weapon,int damage);
void four_kill(object me,object victim,object weapon,int damage);
int five_kill(object me,object victim,object weapon,int damage);
void lovekill(object me,object victim,object weapon,int damage);
void power_slash(object me,object victim, object weapon,int damage);
void heartkill(object me,object victim,object weapon,int damage);
void dream(object me,object victim,object weapon,int damage);
void fast(object me,object victim,object weapon,int damage);
void disenforce(object me, object victim, object weapon, int damage);
void two(object me,object victim,object weapon,int damage);

mapping *action = ({
//1-8招是情剑
//1
([ "action" :NOR"                                  "HBRED"==那一剑的惊艳=="NOR"\n"NOR+
             HIW"$N已挐了$w"HIW"在手，剑如流水，见风就长，剑美，剑法更美，美的像一个受宠若惊，\n"
            +HIW"那一剑不是勾魂，也不是夺魄，而是一种魂尽天涯无飘泊，转成了电的速度，雷的震愕，向$n"HIW"刺来！"NOR,
               "dodge"  :        -15,
               "move"   :        -30,
               "damage" :        180,
               "parry"  :          5,
               "force"  :        200,
               "post_action":  (: two :),
               "damage_type":  "惊吓剑伤",
]),
//2
([ "action" :NOR"                                  "HBRED"==那一剑的浪漫=="NOR"\n"NOR+
             HIW"$w"HIW"迎着冷月闪出爱情一般奇诡的冷芒，在冷月下浮沉了几道寒芒，就像凄美得可以让人\n"
            +HIW"一口逼进的鲸吞，有如剑花般的寂莫，缭绕在$n"HIW"脑里，迂回在$n"HIW"心中，直攻入愁肠！"NOR,
               "dodge"  :         20,
               "move"   :          0,
               "damage" :        200,
               "parry"  :         10,
               "force"  :        200,
               "post_action":  (: two :),
               "damage_type":  "愁怨剑伤",
]),
//3
([ "action" :NOR"                                  "HBRED"==那一剑的凄然=="NOR"\n"NOR+
             HIW"$N心静，手稳，闷哼一声，手中$w"HIW"已刺出点点银光，像一记无意的顾盼，刻意的雷极，\n"
            +HIW"直击$n，剑影如深深的恨，浅浅的梦，又似岁月的泪\痕！"NOR,
               "dodge"  :        -10,
               "move"   :          0,
               "damage" :        180,
               "parry"  :          0,
               "force"  :        250,
               "post_action":  (: lovekill :),
               "damage_type":  "心碎剑伤",
]),
//4
([ "action" :NOR"                                  "HBRED"==那一剑的风情=="NOR"\n"NOR+
             HIW"$N这一剑的意境，无法用言语、用图画、用文字去形容，既不是快、亦不是奇、也不是绝、更不只是优美，\n"
            +HIW"而是一种只应天上有，不应世间无的剑法，$n"HIW"惊愣的脸容在刹那间凝结！"NOR,
               "dodge"  :         10,
               "move"   :         30,
               "damage" :        200,
               "parry"  :         10,
               "force"  :        200,
               "post_action":  (: lockman :),
               "damage_type":  "莫名剑伤",
]),
//5
([ "action" :NOR"                                  "HBRED"==那一剑的灿烂=="NOR"\n"NOR+
             HIW"$N啸声清亮，如鹰戾九宵，剑影交错似如漩涡，又似湖中的涟漪，绵绵不绝，那银芒就宛如夜星般的\n"
            +HIW"令$n"HIW"不知该如何闪避，刹那间溅起了淡淡血光！"NOR,
               "dodge"  :        -10,
               "move"   :          0,
               "damage" :        180,
               "parry"  :          0,
               "force"  :        250,
               "post_action":  (: four_kill :),
               "damage_type":  "点点刺伤",
]),
//6
([ "action" :NOR"                                  "HBRED"==那一剑的潇洒=="NOR"\n"NOR+
             HIW"$N手中的$w"HIW"发出一道淡淡的蓝光，淡的就像是黎明初现的那一抹曙色，来势奇快，无影无形，\n"
            +HIW"剑气激荡，凌厉无比，令$n"HIW"难以抵挡，剑气的锋芒砍入肌骨！"NOR,
               "dodge"  :        -20,
               "move"   :        -20,
               "damage" :        200,
               "parry"  :         20,
               "force"  :        200,
               "post_action":  (: power_slash :),
               "damage_type":  "剑气刺伤",
]),
//7
([ "action" :NOR"                                  "HBRED"==那一剑的哀愁=="NOR"\n"NOR+
             HIW"沧凉古老的剑声，就仿佛和晨雾从虚无缥缈中散发出来的，缥缈的剑声，像是远方伊人的呼唤，\n"
            +HIW"又像是在诉说一种说不出的哀愁，无可奈何的哀愁，却又带着说不出的宁静！"NOR,
               "dodge"  :        -10,
               "move"   :        -10,
               "damage" :        200,
               "parry"  :        -70,
               "force"  :        500,
               "post_action":  (: seven :),
               "damage_type":  "愁怨剑伤",
]),
//8
([ "action" :NOR"                                  "HBRED"==那一剑的寂寞=="NOR"\n"NOR+
             HIW"凄美的剑光让$n"HIW"心神纠缠化成郁结，不哭一声，不诉一声，就把$n"HIW"的记忆导引向要忘了的那一段浮沉，\n"
            +HIW"把白昼换上黄昏的寂寞，让$n"HIW"逐渐失去自己的感觉，而在岁月的微光里平添害怕，而且不甚快乐！"NOR,
               "dodge"  :          0,
               "move"   :          0,
               "damage" :        250,
               "parry"  :          0,
               "force"  :        250,
               "post_action":  (: lovekill :),
               "damage_type":  "忧怨剑伤",
]),
});


mapping query_action(object me,object weapon)
{
        string actionn;
        int limit;
        int skill_level = me->query_skill("love-sword",1);
        if (!userp(previous_object())) skill_level=120;

        limit= skill_level/10;
       if (limit < 2 )
                return action[0];
       else if (limit < 4 )
                return action[random(2)];
       else if (limit < 6 )
                return action[random(3)];
       else if (limit < 7 )
                return action[random(4)];
       else if (limit < 9 )
                return action[random(5)];
       else if (limit < 10 )
                return action[random(6)];
       else if (limit < 11 )
                return action[random(7)];
       else
                return action[random(8)];
}
void two(object me,object victim,object weapon,int damage)
{
     int bell,sk,mk,mk1,i;
     bell = me->query("bellicosity",1);
     sk= me->query_skill("love-sword", 1);
     if (!userp(previous_object())) sk=120;
     mk = me->query("MKS");
     if(mk<8500) {damage = 3*sk;mk1=5;}
     else 
     	if(mk<9000) {damage = 3*sk;mk1=4;}
     else 
     	if(mk<9500) {damage = 3*sk;mk1=3;}
     else 
     	if(mk<10000) {damage = 3*sk;mk1=2;}
     else {damage = 3*sk;mk1=1;}

	if( bell<100 
//	&& me->query_skill_mapped("sword") == "love-sword"  
//	&& me->query_skill_mapped("parry") == "dream-blade"  
	&& damage>0)
 	{
   		message_vision(HIW"\n       刀像一阵风，剑像一缕\烟，来得就像是流水那么自然，不但有了生命，也有了灵气，更有了杀气\n\n"
                	       HIW"                          美丽．光华在闪动．变幻．高高在上．轻云飘忽\n\n"
                  	       HIW"                   $n只觉得这道光华仿佛就在自己眉宇间，又仿佛在虚无缥缈间\n\n"
                  	       HIW"                   它的变化，几乎已超越了人类能力的极限，几乎已令人无法相信\n\n"NOR,me,victim);
	        for(i=0;i<=mk1;i++)
        	{
        	  	victim->receive_damage("qi",damage);
         		 COMBAT_D->report_status(victim);
       		}
 	}
}
void lovekill(object me,object victim,object weapon,int damage)
{
 int bell,mk,skillb;
 bell = me->query("bellicosity");
 mk = (int)me->query("MKS",1);
 skillb = (int)me->query_skill("love-sword",1);
 if (!userp(previous_object())) skillb=120;
if(!me->query_temp("lovekill"))
 {
	 if( random(100) < 60 && mk < 9000 && bell < 100 && damage>0)
   	{

	message_vision("

"HIW"                        "BLINK"‘ 挽留天涯挽留人．挽留岁月挽留你 ’"NOR"

"HIY"--在天愿做比翼鸟．在地愿为连理枝--"NOR"
"HIR"                                       剑意纵横，分影倏忽，仿佛斩出了岁月惊心\n"NOR,me,victim);
             victim->receive_damage("qi",skillb);
             COMBAT_D->report_status(victim);

message_vision("

"HIY"--两情若在长久时．又岂在朝朝暮暮--"NOR"
"HIR"                                       平凡一剑，陷溺迷惘，仿佛带出了岁月痴情\n"NOR,me,victim);
             victim->receive_damage("qi",skillb);
             COMBAT_D->report_status(victim);

message_vision("

"HIY"--天涯地角有穷时．只有相思无尽处--"NOR"
"HIR"                                       剑如彩云，灿烂夺目，仿佛舞出了岁月华彩\n"NOR,me,victim);
             victim->receive_damage("qi",skillb);
             COMBAT_D->report_status(victim);

message_vision("

"HIY"--衣带渐宽终不悔．为伊消得人憔悴--"NOR"
"HIR"                                       剑光闪烁，左右飘荡，仿佛动出了岁月无情\n"NOR,me,victim);
             victim->receive_damage("qi",skillb);
             COMBAT_D->report_status(victim);

message_vision("

"HIY"--无情不似多情苦．一寸还成千万缕\--"NOR"
"HIR"                                       剑意孤独，灰飞烟灭，仿佛幻出了岁月无奈\n"NOR,me,victim);
             victim->receive_damage("qi",skillb);
             COMBAT_D->report_status(victim);

message_vision("

"HIY"--此情可待成追忆．只是当时已惘然--"NOR"
"HIR"                                       剑光一道，夺人心魄，仿佛照出了岁月光华\n"NOR,me,victim);
             victim->receive_damage("qi",2*skillb);
             victim->start_busy(random(2));
             COMBAT_D->report_status(victim);
   	}
  }
  me->delete_temp("lovekill");
}
//busy对手,兼有攻击之功能
void lockman(object me,object victim,object weapon,int damage)
{
        int mk,mecor,victimcor;
        int sk = me->query_skill("love-sword",1);
        if (!userp(previous_object())) sk=120;
        mk = (int)me->query("MKS",1);
        mecor = me->query("cor") + me->query("cps") 
              + me->query("combat_exp")/100000 ;
        victimcor = victim->query("cor") + victim->query("cps") 
                  + victim->query("combat_exp")/100000 ;
        if(!me->query_temp("lockman") && me->query("force") > 50 
        && mk < 10000 && damage > 0)
        {
               me->set_temp("lockman",1);
               me->add("neili",-50);
               victim->start_busy(2);
               if( random(mecor) >= random(victimcor))
                {
                   message_vision(CYN"剑意已夺去$n"CYN"的心志，使$n"CYN"遁入记忆的怆凉里，悲愤的不惜向自己的梦中杀去．．\n"NOR , me , victim );
                   victim->receive_damage("qi",3*sk,me);
 //                  victim->receive_damage("sen",1*(victim->query("max_sen")/10));
                   victim->receive_damage("jing",1*(victim->query("max_jing")/10));
                   if (damage <= 0)
                   COMBAT_D->report_status(victim, 1);
                }
                else{
                        message_vision(sprintf(CYN"剑光夺丽，剑意绝情，$n"CYN"觉得剑花已交织成一张杀意的网！\n"NOR),me,victim);
                }
         }
         else{
                 me->delete_temp("lockman");
         }
}
void four_kill(object me,object victim,object weapon,int damage)
{
 int bell,mk;
 bell = me->query("bellicosity");
 mk = (int)me->query("MKS",1);
 damage= (int)(me->query_skill("love-sword", 1));
 if (!userp(previous_object())) damage=120;
 if(!me->query_temp("four_kill"))
 {
  if( random(100) < 60 && mk < 10000 && bell < 200  && damage>0)
   {
me->set_temp("four_kill",1);
message_vision("\n
                             "HIG"§情真爱又真．快乐是人生§"NOR"\n"NOR,me,victim);
             victim->receive_damage("qi",1*damage);
             COMBAT_D->report_status(victim);

message_vision("
                             "HIB"§情真爱半分．半生空遗恨§"NOR"\n"NOR,me,victim);
             victim->receive_damage("qi",1*damage);
             COMBAT_D->report_status(victim);

message_vision("
                             "HIR"§情爱没缘份．一生不饶人§"NOR"\n"NOR,me,victim);
             victim->receive_damage("qi",1*damage);
             COMBAT_D->report_status(victim);
message_vision("
                             "HIC"§情爱寂寞人．寂寞是人生§"NOR"\n"NOR,me,victim);
             victim->receive_damage("qi",1*damage);
             victim->start_busy(random(2)+1);
             COMBAT_D->report_status(victim);
             call_out("five_kill", 1 ,me);
   }
 }
  me->delete_temp("four_kill");
}
int five_kill(object me,object victim,object weapon,int damage)
{
 int bell = me->query("bellicosity");
 weapon=me->query_temp("weapon");
   message_vision("\n
  "HIY"       $N的人与剑已开始有了动作，一种极缓慢，极优美的动作，就像是风那么自然\n
  "HIY"                    $N的瞳孔在收缩，"+weapon->name()+""HIY"已慢慢的刺了出来\n
  "HIY"             从最不可思议的部位刺了出来，刺出时忽然又有了最不可思议的变化\n
  "HIY"         世上根本没有人能破这一剑，绝对没有任何人能谁想去破这一剑，就是去送死\n\n"NOR,me,victim);
 if(bell < 50 && random(10)>4)
  {

   message_vision(HIR"              血花耀眼又灿烂，灿烂的婉如流星，流星一现即逝，血花也很快的洒下\n"NOR, me);
        victim->add("neili",-1*victim->query("max_neili")/5);
        victim->receive_damage("qi",1*(victim->query("max_qi")/5));
//        victim->receive_damage("sen",1*(victim->query("max_sen")/5));
        victim->receive_damage("jing",1*(victim->query("max_jing")/5));
        victim->start_busy(2);
        me->add("neili",-1*(me->query("neili")/10));
  }
   else
  {
   message_vision(HIR"              血花耀眼又灿烂，灿烂的婉如流星，流星一现即逝，血花也很快的洒下\n"NOR, me);
        victim->add("neili",-1*victim->query("max_neili")/10);
        victim->receive_damage("qi",1*(victim->query("max_qi")/10));
//        victim->receive_damage("sen",1*(victim->query("max_sen")/10));
        victim->receive_damage("jing",1*(victim->query("max_jing")/10));
        victim->start_busy(1);
        me->add("neili",-1*(me->query("neili")/10));
  }
}
void power_slash(object me,object victim, object weapon,int damage)
{
 object *enemy,target,env;
 int i,j,bell;
 bell = me->query("bellicosity");
 damage = victim->query("eff_qi")/20;
 env = environment(me);
 enemy=me->query_enemy();
 i=sizeof(enemy);
 for(j=0;j < i;j++){
 victim=enemy[j];
    if( env == environment(victim) && bell < 100)
    {
     victim->receive_wound("qi", damage);
     switch(random(4)+1)
    {
     case 1 :
     message_vision(sprintf("\n                               "HBCYN"．．此情此景成追忆．．\n"NOR),me,victim);
     message_vision(sprintf(HIW"这么空虚的一剑，不但是刺向$n，还似忘情过去，刺向未来，而且还刺至虚无的任一处．． \n"NOR),me,victim);
     break;
     case 2 :
     message_vision(sprintf("\n                               "HBWHT"．．上天不负有心人．．\n"NOR),me,victim);
     message_vision(sprintf(HIW"半空剑光化作电光，霹雳击下，剑意切入了$n中，卷入了剑气，剑光一闪而殁\．． \n"NOR),me,victim);
     break;
     case 3 :
     message_vision(sprintf("\n                               "HBMAG"．．多情自古空余恨．．\n"NOR),me,victim);
     message_vision(sprintf(HIW"一片紫色剑光仿若海浪般卷向$n，$n眼里没有痛苦，没有悔意，甚至没有一点表情．．\n"NOR),me,victim);
     break;
     case 4 :
     message_vision(sprintf("\n                               "HBGRN"．．情到深处无怨由．．\n"NOR),me,victim);
     message_vision(sprintf(HIW"这一剑之势令$n无法闪躲，就像命宫里的一颗魔星，八字里注定了那么一剑拦在命运里．．\n"NOR),me,victim);
     break;
    }
     COMBAT_D->report_status(victim);
    }
  }
}
void seven(object me,object victim,object weapon,int damage)
{
  int i,mk,da;
  int sk = me->query_skill("love-sword",1);
  if (!userp(previous_object())) sk=120;
  mk = (int)me->query("MKS",1);
  weapon=me->query_temp("weapon");
  if(mk < 10000 ) { da = 130; }
  else { da=100; }
 if( me->query("bellicosity",1) < 200 && mk<10000)
 {
    message_vision(HIW"\n      $N手中握的"+weapon->name()+""HIW"仿佛是杀人的利器，精华，致命的一招，这一招不但诡异．毒辣．准确\n\n"
                 HIW"        $n所有的动作，竟在这一剑使出时忽然间全部停顿，然后苍穹间就溅出了一片花雨\n\n"
                 HIW"                    满天的剑影，满天的血花，剑花又转，由慢转快，由纯变混\n\n"
                 HIW"               忽然又化作一道匹练般的彩红，七色彩红，七剑，多采多姿，千变万化\n\n"NOR,me,victim);
    for(i=1;i<=7;i++)
  {
    switch(i)
    {
     case 1:
message_vision(sprintf(HIR"                       --<<红>>剑意有如风不定．伤遮流景．落红应满径--\n"NOR),me,victim);
     break;
     case 2:
message_vision(sprintf(YEL"                       --<<橙>>剑意有如抛弃久．惆怅依旧．镜里人颜瘦--\n"NOR),me,victim);
     break;
     case 3:
message_vision(sprintf(HIY"                       --<<黄>>剑意有如雨初歇．晓风残月．更与何人说--\n"NOR),me,victim);
     break;
     case 4:
message_vision(sprintf(HIG"                       --<<绿>>剑意有如黯天际．望极春愁．强乐还无味--\n"NOR),me,victim);
     break;
     case 5:
message_vision(sprintf(HIB"                       --<<蓝>>剑意有如乱蝉嘶．酒徒萧索．不似去年时--\n"NOR),me,victim);
     break;
     case 6:
message_vision(sprintf(CYN"                       --<<靛>>剑意有如照无眠．悲欢离合．何似在人间--\n"NOR),me,victim);
     break;
     case 7:
message_vision(sprintf(MAG"                       --<<紫>>剑意有如追忆思．酒入愁肠．化作相思泪\--\n"NOR),me,victim);
     break;
     }
     if( sk > random(30)+100)
     {
message_vision(sprintf(HIC"$n被$N的七色剑意所困，全身上下伤痕累累！\n"NOR),me,victim);
          victim->receive_wound("qi",da,me);
          COMBAT_D->report_status(victim,1);
     }
     else
     {
           message_vision(sprintf(WHT"$n"+WHT"心如止水，看清了$N"+WHT"的剑势！\n"NOR),me,victim);
     }
   }
 }
}
/*
//杀人数以在8000做基准,8000-10000才会强,10000以上会有很多副攻出不来,或是威力不强
//情剑的一剑七色七连击





//杀气小于200,杀人数小于10000,机率约6成,伤害约480


//连接四杀,杀气须小于50威力才会大,机率约55%




//减对手最大气的20%






//.............................................................
//dream-dest和fire-dance在刀剑合壁时以机率判断交互出来
void dream(object me,object victim,object weapon,int damage)
{
     int mk,damagea,damage1,bell,sena,senb;
     mk = (int)me->query("MKS",1);
     if(mk < 10000)  {damagea = mk/10;  }     //mk<10000  ,威力约在800-990
     else { damagea = mk/50; }                //mk>10000  ,威力约在200-600(mk=30000)
                                              //杀人数越少,威力才会强
     damage1= random(damagea)+damagea;
     bell = me->query("bellicosity",1);
     sena = victim->query("max_sen");
     senb = sena/10;
  if( bell<100 && me->query_skill_mapped("sword") == "love-sword"  && me->query_skill_mapped("parry") == "dream-blade" && damage>0 )
   {
    if(random(100)>50)
     {
       message_vision(HIW"\n
         $N右手自左腋出手一刀，刀光．一闪．一闪的刀光．刀上蓝焰大盛！\n
        "HIW"天地间飘曳起一道幽幽蓝光，似真似幻，如沉静的月光投入深邃的大海 \n
               "HIW"这一刀，极快、极速、极简单、看去极平凡无奇．．． \n
               "HIW"然而却是“相思碎梦”一千零一式中所有的精华和杀招！\n
                           "HIW"‘"HIR"舞刀．卷尘．风行斩"HIW"’ \n\n"NOR, me);

              me->add("force",-random(300));
              victim->receive_damage("qi",1*damage1);
              victim->receive_damage("sen",senb);
              COMBAT_D->report_status(victim);
      }
      else
      {
        message_vision(HIW"\n
           一种乍看令人心动，细看足以让人心血贲动的红光，自刀身透了出来\n
                    "HIW"血红般的刀气有如太阳西下般撩绕在$n的周围\n
              "HIW"$n只觉得又快、又奇、又绝、惊艳、潇洒、惆怅、不可一世\n
                                  "HIW"‘"HIC"烽火红尘路"HIW"’\n"NOR,me,victim);

        message_vision(HBRED"\n$N的烽火刀气让$n乱了方寸，迷失在烽火红尘之中！\n"NOR,me,victim);
        victim->start_busy(random(4)+1);
        victim->receive_damage("qi",1*damagea);
      }
   }
}


//相思碎梦刀诀的八连击
void heartkill(object me,object victim,object weapon,int damage)
{
  int i;
  message_vision(HIC"\n\n\t只见$N的身形随着刀式一变，刀身闪出无数耀眼的光芒，震出了一片茫茫的刀幕\n\n"
                 HIW"\t～～"BLINK""HIR"   忘弃红尘．相思八律  "NOR""HIW"  ～～\n\n"NOR,me,victim);
    for(i=1;i<=8;i++)
  {
    switch(i)
     {
     case 1:
message_vision(sprintf(HIY"$N心如刀割，黯然神伤，使出"HIR"忘弃红尘"HIW"之"+NOR+""+RED+"「伤心律”"+NOR+""+HIY+"，刀势如乱麻般攻向$n！\n"NOR),me,victim);
     break;
     case 2:
message_vision(sprintf(HIY"$N心烦意乱，念念不忘，使出"HIR"忘弃红尘"HIW"之"+NOR+""+GRN+"「扣心弦”"+NOR+""+HIY+"，刀势如惋伤般紧扣$n！\n"NOR),me,victim);
     break;
     case 3:
message_vision(sprintf(HIY"$N心力交悴，怅然若失，使出"HIR"忘弃红尘"HIW"之"YEL"「碎心声”"+NOR+""+HIY+"，刀势如凄怆般席卷$n！\n"NOR),me,victim);
     break;
     case 4:
message_vision(sprintf(HIY"$N心不在焉，神不守舍，使出"HIR"忘弃红尘"HIW"之"MAG"「失心乐”"+NOR+""+HIY+"，刀势如忘情般幻惑$n！\n"NOR),me,victim);
     break;
     case 5:
message_vision(sprintf(HIY"$N心不由主，失魂落魄，使出"HIR"忘弃红尘"HIW"之"+NOR+""+CYN+"「惑心音”"+NOR+""+HIY+"，刀势如鬼魅般迷惑$n！\n"NOR),me,victim);
     break;
     case 6:
message_vision(sprintf(HIY"$N心如死灰，情至义尽，使出"HIR"忘弃红尘"HIW"之"HIB"「葬心曲”"+NOR+""+HIY+"，刀势如怒涛般涌向$n！\n"NOR),me,victim);
     break;
     case 7:
message_vision(sprintf(HIY"$N心有余悸，恨海难填，使出"HIR"忘弃红尘"HIW"之"HIC"「余心韵”"+NOR+""+HIY+"，刀势如悲凉般牵引$n！\n"NOR),me,victim);
     break;
     case 8:
message_vision(sprintf(HIY"$N心凝形释，平心静气，使出"HIR"忘弃红尘"HIW"之"HIW"「定心调”"+NOR+""+HIY+"，刀势如无形般直取$n。\n"NOR),me,victim);
     break;
     }
     if( me->query_skill("dream-blade",1)> random(60)+100)
     {
message_vision(sprintf(MAG"结果被$N确确实实的命中要害，$n身上立即多了一道无情的伤痕！\n"NOR),me,victim);
          victim->receive_wound("qi",90,me);

          COMBAT_D->report_status(victim,1);

     }
     else
     {
           message_vision(sprintf(HIB"结果$N的攻击被$n避了开来！\n"NOR),me,victim);
     }
   }
}


//相思碎梦刀诀的奥义三连击
void fast(object me,object victim,object weapon,int damage)
{
    int i;

    if( userp(me) && !me->query("yi/dream") ) return;
    if(( (int)me->query("force") > 300 ) && me->query("force_factor") && me->query("bellicosity") < 200  && damage>0)
    {
       message_vision(CYN"\n\n\t$N笑意微泛，眼里仿佛出现一道阴影，一瞬而过，刀光一闪。。。\n\n"
                            HIW"\t～～"BLINK""HIR"  碎梦奥义．回天梦舞"NOR""HIW"  ～～\n\n"NOR,me,victim);
       for(i=1;i<=3;i++)
       {
         switch(i)
         {
            case 1:
            message_vision(HIY"\n＝＝"HIR"醉   梦"HIY"＝＝\n"NOR,me,victim);
            message_vision(HIW"刀荡刀风，刀美如梦，彩色缤纷，绝美的刀光，如同惊艳遇着风华，\n空间为奇彩所充满，"
                                       +"五彩光华，如痴如醉，似一连串的迷梦在空中闪现，\n迷绚于一连串梦一般的幻像里。。\n"NOR,me,victim);
             break;

            case 2:
            message_vision(HIY"\n＝＝"HIR"惊   梦"HIY"＝＝\n"NOR,me,victim);
            message_vision(HIW"刀光绰约，腾起一阵凌厉而且艳丽的杀意，刀气如浪分涛裂似排山倒海的击出，\n"+
                                         "刀光散开，发出夺目的光彩，血似的鲜红色，凄艳亮烈，惊醒彩色的梦。。\n"NOR,me,victim);
             break;

            case 3:
            message_vision(HIY"\n＝＝"HIR"碎   梦"HIY"＝＝\n"NOR,me,victim);
            message_vision(HIW"天雷忽起，大地浮沉，刀光摒出一道道的强光，裂苍天而出，震苍生而鸣，狂飙忽起，\n"+
                                        " 仿佛潜伏地底的怒龙，裂梦而起，上七重天，升九万里，势所无匹。。\n"NOR,me,victim);
             break;
           }
           if( me->query_skill("dream-blade",1) > random(60)+100)
           {
                  message_vision(MAG"\n$N的刀法舞的如梦似幻，$n身上着了一道深可见骨的伤痕却不自知！\n"NOR,me,victim);
                  victim->receive_wound("qi",400,me);
                  me->add("force",-50);
                  if(i != 3)
                  COMBAT_D->report_status(victim,1);
                  else if( damage <=0 )
                  COMBAT_D->report_status(victim,1);
           }
            else
            {
                  message_vision(HIB"$n看清了$N的攻势，不徐不疾的避了开来！\n"NOR,me,victim);
            }
        }
    }
}




//打掉对手的enforce
void disenforce(object me, object victim, object weapon, int damage)
{
        int skillb = (int)me->query_skill("love-sword",1);
        int me_jing = me->query("max_jing")/5;
        int me_qi = me->query("max_qi")/10;
        int me_sen = me->query("max_sen")/5;
        int victimenf = victim->query("force_factor");
        if( !me->query_temp("disenforce"))
        {
          if(skillb >= 100 && me->query("bellicosity",1)<30 && damage>0 && victimenf > 0)
            {
                message_vision(HIR"\n
             $N的刀剑本来是平淡毫无变化，却忽然间，剑尖起了一种很奇异的震动\n\n"
HIR"              刀势本来很快，就在这时忽然慢了下来，很慢，虽然慢，却还是在变\n\n"
HIR"                        光芒在现，剑锋迥异，刀光如幻，诡异的闪动\n\n"
HIR"                $n觉得这份诡异仿佛就在自己眉睫间，又仿佛在虚无的缥缈间\n\n"
NOR"            "HBBLU"刀光剑意已侵入$n神志，粉碎了$n的斗志，让$n尽往回忆的伤悲处走\n"NOR, me, victim);
                me->set_temp("disenforce",1);
                victim->set("force_factor", 0);
                me->receive_wound("jing",me_jing,me);
                me->receive_wound("qi",me_qi,me);
                me->receive_wound("sen",me_sen,me);
            }else{ message_vision(NOR"\n"NOR,me,victim);}
        }
        else {me->delete_temp("disenforce");}
}
*/
int valid_learn(object me)
{
        int bell, skill;
        object ob;
        bell = me->query("bellicosity");
        skill =me->query_skill("love-sword", 1);
        if(me->query("get-2skill-s") != 1 )         //解love-sword的mark
        {
         tell_object(me, HIY"王小石说道：你我既无师徒之实，怎么叫我传授剑法给你！\n"NOR);
         return 0;
         }
         else
         {
         if( me->query("family/master_name") != "王小石" )
         {
                tell_object(me, HIY"王小石说道：你我既无师徒之实，怎么叫我传授剑法给你！\n"NOR);
                return 0;
         }
         if((int)me->query("max_force") < 2000)
         {
                tell_object(me, HIY"王小石说道：你的内力修为似乎不足以修练「情剑”！\n"NOR);
                return 0;
         }
         if( !(ob = me->query_temp("weapon")) || (string)ob->query("skill_type") != "sword" )
         {
                tell_object(me, HIY"王小石说道：没拿剑怎么练剑法啊！\n"NOR);
                return 0;
         }
         if( (me->query("potential") - me->query("learned_points")) < 5 ) {
                tell_object(me, "你的潜能不到五点, 无法练此剑法。\n");
                return 0;
         }
         if( bell > 100 )
         {
                tell_object(me, HIY"王小石说道：你心存杀念, 怎么能够学习情剑呢！\n");
                return 0;
         }
        tell_object(me, HIY"王小石说道：学此剑法需扣潜能、精、气各五点。\n");
        me->add("jing", -5);
        me->add("qi", -5);
//        me->add("sen", -5);
        me->add("potential", -5);
        return 1;
       }
}
int valid_enable(string usage)
{
        return usage== "sword" || usage=="parry";
}
/*
string perform_action_file(string action)
{
        return CLASS_D("blademan")+"/love-sword/"+action;
}

string exert_action_file(string action)
{
        return CLASS_D("blademan")+"/love-sword/"+action;
}
*/