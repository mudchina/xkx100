// lu.c

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_job();

mapping *names=({
      (["name":                "宋远桥",
       "where" :              "武当派",]),  
      (["name":                "俞莲舟",
       "where" :              "武当派",]),  
      (["name":                "莫声谷",
       "where" :              "武当派",]),
      (["name":                "俞岱岩",
       "where" :              "武当派",]),
      (["name":                "张松溪",
       "where" :              "武当派",]), 
      (["name":                "殷梨亭",
       "where" :              "武当派",]), 
      (["name":                "谷虚道长",
       "where" :              "武当派",]), 
      (["name":                "沙通天",
       "where" :              "黄河四鬼",]), 
      (["name":                "侯通海",
       "where" :              "黄河四鬼",]), 
      (["name":                "钱青健",
       "where" :              "黄河四鬼",]),
      (["name":                "彭连虎",
       "where" :              "黄河四鬼",]),
      (["name":                "空空儿",
       "where" :              "丐帮",]),
      (["name":                "林震南",
       "where" :              "福威镖局",]),
      (["name":                "包不同",
       "where" :              "慕容世家",]),
      (["name":                "风波恶",
       "where" :              "慕容世家",]),
      (["name":                "邓百川",
       "where" :              "慕容世家",]),
      (["name":                "殷野王",
       "where" :              "明教",]),
      (["name":                "苏梦清",
       "where" :              "峨嵋派",]),
      (["name":                "李明霞",
       "where" :              "峨嵋派",]),
      (["name":                "贝锦仪",
       "where" :              "峨嵋派",]),
      (["name":                "方碧琳",
       "where" :              "峨嵋派",]),
      (["name":                "静迦师太",
       "where" :              "峨嵋派",]),
      (["name":                "静照师太",
       "where" :              "峨嵋派",]),
      (["name":                "静虚师太",
       "where" :              "峨嵋派",]),
       (["name":                "静空师太",
       "where" :              "峨嵋派",]),
       (["name":                "静真师太",
       "where" :              "峨嵋派",]),
       (["name":                "静闲师太",
       "where" :              "峨嵋派",]),
       (["name":                "静玄师太",
       "where" :              "峨嵋派",]),
       (["name":                "静慧师太",
       "where" :              "峨嵋派",]),
       (["name":                "阿紫",
       "where" :              "星宿派",]),
       (["name":                "天狼子",
       "where" :              "星宿派",]),
       (["name":                "慧名尊者",
       "where" :              "少林派",]),
       (["name":                "慧修尊者",
       "where" :              "少林派",]),
       (["name":                "慧虚尊者",
       "where" :              "少林派",]),
       (["name":                "慧空尊者",
       "where" :              "少林派",]),
       (["name":                "慧合尊者",
       "where" :              "少林派",]),
       (["name":                "慧洁尊者",
       "where" :              "少林派",]),
       (["name":                "慧色尊者",
       "where" :              "少林派",]),
       (["name":                "慧如尊者",
       "where" :              "少林派",]),
       (["name":                "慧真尊者",
       "where" :              "少林派",]),
       (["name":                "玄难大师",
       "where" :              "少林派",]),
       (["name":                "玄苦大师",
       "where" :              "少林派",]),
       (["name":                "玄悲大师",
       "where" :              "少林派",]),
       (["name":                "玄慈大师",
       "where" :              "少林派",]),
       (["name":                "玄痛大师",
       "where" :              "少林派",]),
       (["name":                "澄意",
       "where" :              "少林派",]),
       (["name":                "澄灵",
       "where" :              "少林派",]),
       (["name":                "澄和",
       "where" :              "少林派",]),
       (["name":                "澄尚",
       "where" :              "少林派",]),
       (["name":                "澄欲",
       "where" :              "少林派",]),
       (["name":                "澄观",
       "where" :              "少林派",]),
       (["name":                "澄知",
       "where" :              "少林派",]),
       (["name":                "澄思",
       "where" :              "少林派",]),
       (["name":                "澄明",
       "where" :              "少林派",]),
       (["name":                "澄信",
       "where" :              "少林派",]),
       (["name":                "澄识",
       "where" :              "少林派",]),
       (["name":                "澄心",
       "where" :              "少林派",]),
       (["name":                "澄寂",
       "where" :              "少林派",]),
       (["name":                "澄坚",
       "where" :              "少林派",]),
       (["name":                "澄净",
       "where" :              "少林派",]),
       (["name":                "澄行",
       "where" :              "少林派",]),
       (["name":                "澄灭",
       "where" :              "少林派",]),
      (["name":                "史青山",
       "where" :              "扬州守将",]),
      (["name":                "殷天正",
       "where" :              "明教",]),
      (["name":                "周颠",
       "where" :              "明教",]),
      (["name":                "说不得",
       "where" :              "明教",]),
      (["name":                "张中",
       "where" :              "明教",]),
      (["name":                "辛然",
       "where" :              "明教",]),
     (["name":                "范遥",
       "where" :              "明教",]),
     (["name":                "清法比丘",
       "where" :              "少林派",]),
     (["name":                "清无比丘",
       "where" :              "少林派",]),
     (["name":                "马钰",
       "where" :              "全真教",]),
     (["name":                "谭处端",
       "where" :              "全真教",]),
     (["name":                "刘处玄",
       "where" :              "全真教",]),
     (["name":                "丘处机",
       "where" :              "全真教",]),
     (["name":                "王处一",
       "where" :              "全真教",]),
     (["name":                "郝大通",
       "where" :              "全真教",]),
     (["name":                "孙不二",
       "where" :              "全真教",]),
     (["name":                "尹志平",
       "where" :              "全真教",]),
     (["name":                "赵志敬",
       "where" :              "全真教",]),
     (["name":                "崔志方",
       "where" :              "全真教",]),
     (["name":                "张志光",
       "where" :              "全真教",]),
     (["name":                "申志凡",
       "where" :              "全真教",]),
     (["name":                "祁志诚",
       "where" :              "全真教",]),
     (["name":                "李志常",
       "where" :              "全真教",]),
     (["name":                "王志坦",
       "where" :              "全真教",]),
     (["name":                "王志谨",
       "where" :              "全真教",]),
     (["name":                "陈志益",
       "where" :              "全真教",]),
     (["name":                "房志起",
       "where" :              "全真教",]),
     (["name":                "程瑶迦",
       "where" :              "全真教",]),
     (["name":                "宋德方",
       "where" :              "全真教",]),
     (["name":                "于道显",
       "where" :              "全真教",]),
       });   
void create()
{
	set_name("鲁有脚", ({"lu youjiao", "lu", "youjiao"}));
	set("gender", "男性");
	set("age", 45);
	set("long", 
		"鲁有脚虽然武功算不得顶尖高手，可是在江湖上却颇有声望。\n"
		"因为他在丐帮中有仁有义，行事光明磊落，深得洪七公的器重。\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 9);
	set("str", 25);
	set("int", 12);
	set("con", 25);
	set("dex", 20);

	set("qi", 900);
	set("max_qi", 900);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 100);
	set("no_get", 1);
	
	set("combat_exp", 100000);
	set("score", 20000);
	
	set_skill("force", 90); // 基本内功
	set_skill("huntian-qigong", 90); // 混天气功
	set_skill("parry", 90); // 基本招架
	set_skill("hand", 95); // 基本手法
	set_skill("suohou-hand", 95); // 基本手法
	set_skill("strike", 95); // 基本掌法
	set_skill("xianglong-zhang", 90); // 降龙十八掌
	set_skill("dodge", 90); // 基本躲闪
	set_skill("xiaoyaoyou", 90); // 逍遥游
	set_skill("staff", 85); // 基本杖法
	set_skill("fengmo-staff", 85); // 疯魔杖法
	set_skill("stick", 85); // 基本棒法
	set_skill("dagou-bang", 45); // 打狗棒法
	set_skill("begging", 60);
	
	set_skill("lianhua-zhang",85); // 莲花掌

	map_skill("force", "huntian-qigong");
	map_skill("parry", "xianglong-zhang");
	map_skill("strike", "xianglong-zhang");
	map_skill("hand", "suohou-hand");
	map_skill("staff", "fengmo-staff");
	map_skill("stick", "dagou-bang");
	map_skill("dodge", "xiaoyaoyou");
	prepare_skill("strike", "xianglong-zhang");
	set("inquiry", 
	([
		"送信" : (: ask_job :),
		"letter" : (: ask_job :),
	]));
	set("party/party_name", HIC"丐帮"NOR);
	set("party/rank", RED"九袋长老"NOR);
	set("party/level", 9);
	create_family("丐帮", 18, "掌棒龙头");

	setup();

	carry_object(__DIR__"obj/jiaohuaji");
	carry_object(__DIR__"obj/cloth")->wear();
	carry_object(WEAPON_DIR"gangzhang")->wield();
}

void attempt_apprentice(object ob)
{
	if ( (int)ob->query("int") >= 25 )
	{
		command("say 我们丐帮的武艺一向以刚猛为主，" + 
		RANK_D->query_respect(ob) + "聪慧过人，似乎不宜学丐帮的功夫？");
		return;
	}
	command("say 好吧，希望" + RANK_D->query_respect(ob) +
		"能好好学习本门武功，将来在江湖中闯出一番作为。");
	command("recruit " + ob->query("id"));
}

string ask_job()
{
	object me;
	object ob;
	int time;
	mapping target, fam;
  	ob=this_player();
	me=this_object();
/*
	if (!(fam = me->query("family")) || fam["family_name"] != "丐帮")
		return RANK_D->query_respect(me) + "与丐帮素无来往，此话从何说起？";
*/
	if (ob->query_temp("gb_songxin")&&present("secret letter", this_player()))
		return ("你不是已经领了送信的任务吗？还不快去做。\n");
	if (ob->query_condition("gb_songxin") > 1) 
	    { time=1;
	      ob->apply_condition("gb_songxin",time);
	     } 
	if (ob->query_condition("gb_songxin") > 0)
	     {  
		return "现在暂时没有给你的任务，再等"+chinese_number(ob->query_condition("gb_songxin"))+"柱香的时间吧。";
	      }
	if (ob->query("combat_exp")>=30000 && !wizardp(ob))
		return "我看你的武功已有相当的功底了，就不用在我这里干事了。\n";
	if (ob->query("combat_exp")<100 && !wizardp(ob))
		return "你的功夫还不够啊，送信可是很危险的事，我可不敢交给你任务。\n";
 
	target = names[random(sizeof(names))];
	
	time = random(10)+(80-2*ob->query("int"));
	if (ob->query("combat_exp")>=10000 && !wizardp(ob))
	    time = time*4/5;
	if (ob->query("combat_exp")>=20000 && !wizardp(ob))
	    time = time*2/3;   
	    
	ob->delete_temp("songxin_ok");
	ob->delete_temp("gb_songxin_late");

	ob->set_temp("gb_songxin",1);
	ob->set_temp("songxin_time",time);
	ob->set_temp("songxin_target_name", target["name"]);
	ob->set_temp("songxin_where", target["where"]);
	ob->delete_temp("songxin_zuji");
	ob->apply_condition("gb_songxin",time);
	switch(random(3))
	{
		case 0:
			message_vision("$N悄悄把$n拉到一旁，低声说道，你把这封密函火速送到「"+ob->query_temp("songxin_where")+"」"
"的「"+ob->query_temp("songxin_target_name")+"」手上。\n",me,ob);
			message_vision("$N交给$n一封密函。\n",me,ob);
			ob=new(__DIR__"obj/letter");
			ob->set_temp("no_get", 1);  
			break;
		case 1:
	        message_vision("$N点了点头，说道，我这里正好有封信，你去把它送到「"+ob->query_temp("songxin_where")+"」\n的「"+ob->query_temp("songxin_target_name")+"」手上。\n",me,ob);
			message_vision("$N交给$n一封信。\n",me,ob);
			ob=new(__DIR__"obj/letter");
			ob->set_temp("no_get", 1);
			break;
		case 2:
			message_vision("$N微微一笑，从怀中掏出一封信，说道，你赶紧把它送到「"+ob->query_temp("songxin_where")+"」\n的「"+ob->query_temp("songxin_target_name")+"」手上。\n",me,ob);
			message_vision("$N交给$n一封信。\n",me,ob);
			ob=new(__DIR__"obj/letter");
			ob->set_temp("no_get", 1);
			break;
	}
	
	ob->move(this_player());
	return "路上常有强人出没，务必小心。。";
}
#include "/kungfu/class/gaibang/gaibang.h"
