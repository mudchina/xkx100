// saite.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
int do_noodle();
int do_linqiyan();
int do_baoer();
int do_yuki();
int do_ftlsk();
void create()
{
	set_name("赛特", ({ "saite"}));
	set("gender", "男性");
	set("long","自2001年接触xkx100以来，一直是这里的忠实拥护者。从此在
这里常常能看到他的身影。其间帮助新手老手无数，受到众玩
家的喜爱。可惜终生未得一红颜知己，仅有一至交萧邪相伴，
共同享受泥潭乐趣。其培养的很多id号如kofc ssread等都曾
经夺取过比武大会名次。泥潭晚期对编写机器人及解迷产生浓
厚兴趣，并由此发现不少大小bug，虽对泥潭日益熟悉，但人非
圣贤，许多迷题终不得解，引为憾事，逍遥而去。\n");
	set("title", NOR"逍遥派第三代弟子"NOR);
	set("nickname", HIC"我就只能当她哥们吧.."NOR);
	set("age", 34);
	set("class", "swordman");
	set("attitude", "friendly");

	set("kar", 20);
	set("per", 30);
	set("int", 37);
	set("dex", 40);
	set("con", 35);
	set("str", 40);
	set("weiwang", 50);
	set("shen", -802282);
	set("combat_exp", 1691661);
	set("PKS", 2);
	set("MKS", 7449);

	set("max_jing", 570);
	set("jing", 570);
	set("max_qi", 982);
	set("qi", 982);
	set("max_jingli", 600);
	set("jingli", 600);
	set("max_neili", 8130);
	set("neili", 8130);
	set("meili", 60);

	set_skill("literate", 175);
	set_skill("taoism", 120);
	set_skill("force", 200);
	set_skill("unarmed",100);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("construction", 10);
	set_skill("hubo", 200);
	set_skill("qimen-wuxing", 101);
	set_skill("claw", 151);
	set_skill("sword", 601);
	set_skill("training", 39);
	set("env/no_teach", "1");

	set_skill("shenzhao-jing", 157);
	set_skill("jinshe-jian", 200);
	set_skill("jinshe-zhui", 200);
	set_skill("jiuyin-baiguzhao", 171);
	set_skill("beiming-shengong", 200);
	set_skill("kongming-quan", 1);
	set_skill("lingboweibu", 204);
	set_skill("tianyu-qijian", 202);
	map_skill("dodge", "lingboweibu");
	map_skill("parry", "tianyu-qijian");
	map_skill("throwing", "jinshe-zhui");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("sword","tianyu-qijian");
	prepare_skill("claw","jiuyin-baiguzhao");

	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"noodle"  : (: do_noodle :),
		"linqiyan": (: do_linqiyan :),	
		"yuki"	: (: do_yuki :),
		"baoer" : (: do_baoer :),
		"ftlsk" : (: do_ftlsk :),
	]));

	create_family("逍遥派",2, "弟子");
	setup();
//	carry_object(__DIR__"saite_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
    carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N说： 我所有的基本武功如下：\n"+

"≡─────────────────────────────────≡\n"+
"  北冥神功 (beiming-shengong)              - 心领神会 200/  173\n"+
"  基本爪法 (claw)                          - 已有小成 151/  163\n"+
"  土木机关 (construction)                  - 新学乍用  10/   48\n"+
"  基本轻功 (dodge)                         - 心领神会 200/  198\n"+
"  基本内功 (force)                         - 心领神会 200/   31\n"+
"  左右互搏 (hubo)                          - 半生不熟 100/    0\n"+
"  金蛇剑法 (jinshe-jian)                   - 心领神会 200/  527\n"+
"□金蛇锥法 (jinshe-zhui)                   - 心领神会 200/    8\n"+
"□九阴白骨抓 (jiuyin-baiguzhao)            - 驾轻就熟 171/14648\n"+
"  空明拳 (kongming-quan)                   - 不堪一击   1/    0\n"+
"□凌波微步 (lingboweibu)                   - 心领神会 204/41847\n"+
"  读书写字 (literate)                      - 已有小成 175/ 3851\n"+
"  基本招架 (parry)                         - 心领神会 200/ 1119\n"+
"  奇门五行 (qimen-wuxing)                  - 半生不熟 101/    0\n"+
"□神照经 (shenzhao-jing)                   - 已有小成 157/17362\n"+
"  基本剑法 (sword)                         - 心领神会 201/ 1413\n"+
"  道学心法 (taoism)                        - 马马虎虎 120/  314\n"+
"□天羽奇剑 (tianyu-qijian)                 - 心领神会 202/ 6566\n"+
"  驭兽术 (training)                        - 初窥门径  39/  828\n"+
"  基本拳脚 (unarmed)                       - 平淡无奇 100/   22\n"+
"≡─────────────────────────────────≡\n", this_object());
	return 1;
}

int do_hp()
{
message_vision("$N说： 我的基本状态如下：\n\n"+
"≡──────────────────────────────≡\n"+
"【 精 气 】  570/  570 (100％)   【 精 力 】  600 /  600 (+0)\n"+
"【 气 血 】  982/  982 (100％)   【 内 力 】 2570 / 2570 (+0)\n"+
"【 戾 气 】 -802282              【 体 力 】  276 /  276\n"+
"【 食 物 】  350/  350           【 潜 能 】  307\n"+
"【 饮 水 】  350/  350           【 经 验 】  1691661\n"+
"≡──────────────────────────────≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N说： 我的基本状况如下：\n\n"+
"【 魔  王 】逍遥派第三代弟子「我就只能当她哥们吧...」赛特(Saite)\n"+
"\n"+
" 你是一位三十四岁四个月性格普通的男性人类，己卯年三月七日辰时四刻生。\n"+
" 膂力[25/ 40]  悟性[20/ 37]  根骨[15/ 35]  身法[20/ 40]  耐力[11/ 31]\n"+
" 灵性[18/ 30]  福缘[20/ 20]  胆识[30/ 30]  定力[21/ 21]  容貌[18/ 18]\n"+
"\n"+
" 你的师父是 心伤。        你还是个光棍。\n"+
" 存款：一千九百三十三两黄金二十七两白银。\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 食物：■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" 饮水：■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 到目前为止你总共杀了 7449 个人，其中有 2 个是其他玩家。\n"+
" 到目前为止你总共杀了 3 个同门，其中有 0 个是你的师长。\n"+
" 到目前为止你总共杀了 3 个帮中弟兄，其中有 0 个是你的上司。\n"+
" 到目前为止你总共杀了 3564 个无辜百姓，其中有 28 个是儿童。\n"+
" 到目前为止你总共死了 5 次了，其中有 3 次是非正常死亡。\n"+
" 到目前为止你总共叛师了 0 次了，被开除了 0 次。\n"+
"\n"+
" 戾    气：  -802282     潜    能： 307 ( 99%)   实战经验：  1691661\n"+
" 魅    力：       60     江湖阅历：    25236     江湖威望：       50\n"+
"\n", this_object());
	return 1;
}

int do_noodle()
{message_vision("$N说：他呀，是我的铁哥们，我们一起挖泥大半生了。喏，就在我身边呢
。\n",this_object());
	return 1;
}

int do_linqiyan()
{message_vision("$N说：小燕子阿，他是我在学校一起玩飞雪的兄弟了。他比他师兄影
枫可安静多了，最不喜欢出风头\n",this_object());
	return 1;
}

int do_baoer()
{message_vision("$N说：铃の宝ル呀，她是我在泥潭中唯一心怡的人了，可惜初次认识时，
她已经有心上人了。唉，什么时候才能再见到她啊....\n",this_object());
	return 1;
}

int do_yuki()
{message_vision("$N说：你说徐怀钰啊，他可是我的老前辈。这家伙的篮球技术可了不得，
篮板\n"+
"三分样样拿手。高是够高了，就是瘦了点，做校篮球队主力还差那么一些体力。\n",this_object());
	return 1;
}

int do_ftlsk()
{message_vision("$N说：凯子这家伙，有事没事就给我找麻烦。不过也没办法，谁叫我\n"+
"比他玩得早呢。想想虾米时候要再敲他几顿饭爽爽。heihei  \n",this_object());
	return 1;
}



