// top.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("冷枫", ({ "top"}));
	set("gender", "男性");
	set("long","雪山派弟子，天赋异禀，年少时只身一人远游西域，投师雪山。
短短数年即已名扬天下。成名后浪迹天涯，武学境界一日千里。
某年春暖花开之际，牵马漫步江南雨巷，邂逅一位冰雪佳人，两
情相悦，遂结为夫妻，从此淡出江湖，晚年开创逍遥门，属下门
徒甚众，乃武林第一帮派也。他年近花甲，两鬓斑白，额上几道
深深的皱纹，略显孤单的目光，恰似秋凉时片片枫叶飘落的沧桑。\n");
	set("title", HIW"圣人"NOR"逍遥门门主"NOR);
	set("nickname", HIY"福"HIR" 星"HIG" 高"HIB" 照"NOR);
	set("age", 56);
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 26);
	set("int", 24);
	set("dex", 11);
	set("con", 24);
	set("str", 26);
	set("weiwang", 80);
	set("shen", 1744183791);
	set("combat_exp", 9138500);
	set("PKS", 19);
	set("MKS", 11831);

	set("max_jing", 522);
	set("jing", 522);
	set("max_qi", 3011);
	set("qi", 3011);
	set("max_jingli", 154);
	set("jingli", 154);
	set("max_neili", 5002);
	set("neili", 5002);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 272);
	set_skill("force", 290);
	set_skill("parry", 382);
	set_skill("dodge", 320);
	set_skill("sword", 303);
	set_skill("cuff", 298);
        set_skill("houquan",440);
        set_skill("dashou-yin",400);
        set_skill("blade",339);
        set_skill("claw",298);
        set_skill("hubo",138);
        set_skill("huoyan-dao",435);
        set_skill("hand",298);
        set_skill("hammer",298);
        set_skill("liangyi-jian",428);
        set_skill("mingwang-jian",419);
        set_skill("necromancy",198);
        set_skill("qiankun-danuoyi",248);
        set_skill("qiufeng-chenfa",424);
        set_skill("riyue-lun",423);
        set_skill("shenxing-baibian",429);
        set_skill("strike",298);
        set_skill("taiji-jian",415);
        set_skill("taiji-quan",330);
        set_skill("taiji-shengong",332);
        set_skill("taoism",150);
        set_skill("unarmed",311);
        set_skill("wuhu-duanmendao",201);
        set_skill("xue-dao",438);
        set_skill("yujiamu-quan",400);
        set_skill("taixuan-gong",278);

	map_skill("unarmed", "houquan");
	map_skill("hand", "dashou-yin");
	map_skill("sword", "liangyi-jian");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("force", "taiji-shengong");
	map_skill("cuff", "yujiamu-quan");
	map_skill("parry", "taiji-jian");
	map_skill("whip", "qiufeng-chenfa");
	map_skill("claw", "jiuyin-baiguzhao");
	map_skill("strike", "huoyan-dao");
	map_skill("dodge", "shenxingbaibian");
	map_skill("hammer", "riyue-lun");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("雪山寺",6, "弟子");
	setup();
	carry_object(__DIR__"top_sword")->wield();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N说： 我所有的基本武功如下：\n"+
"  基本刀法 (blade)                         - 深不可测 339/   44\n"+
"  基本爪法 (claw)                          - 深不可测 298/   12\n"+
"  基本拳法 (cuff)                          - 深不可测 298/    1\n"+
"□密宗大手印 (dashou-yin)                  - 超凡入圣 400/18380\n"+
"  基本轻功 (dodge)                         - 深不可测 320/51443\n"+
"  基本内功 (force)                         - 深不可测 352/13145\n"+
"  基本锤法 (hammer)                        - 深不可测 298/   21\n"+
"  基本手法 (hand)                          - 深不可测 298/    2\n"+
"□猴拳 (houquan)                           - 超凡入圣 440/71026\n"+
"  左右互搏 (hubo)                          - 了然於胸 138/    0\n"+
"□火焰刀 (huoyan-dao)                      - 超凡入圣 435/  195\n"+
"□九阴白骨抓 (jiuyin-baiguzhao)            - 深不可测 211/    0\n"+
"□两仪剑法 (liangyi-jian)                  - 超凡入圣 428/    1\n"+
"  读书写字 (literate)                      - 深不可测 272/ 1583\n"+
"  不动明王剑 (mingwang-jian)               - 超凡入圣 419/    0\n"+
"  降伏法 (necromancy)                      - 一代宗师 198/  106\n"+
"  基本招架 (parry)                         - 深不可测 382/40526\n"+
"  乾坤大挪移 (qiankun-danuoyi)             - 深不可测 248/    0\n"+
"□秋风拂尘 (qiufeng-chenfa)                - 超凡入圣 424/32382\n"+
"□日月轮法 (riyue-lun)                     - 超凡入圣 423/84670\n"+
"□神行百变 (shenxing-baibian)              - 超凡入圣 429/ 6500\n"+
"  基本掌法 (strike)                        - 深不可测 298/    0\n"+
"  基本剑法 (sword)                         - 深不可测 303/   69\n"+
"□太极剑法 (taiji-jian)                    - 超凡入圣 415/134233\n"+
"  太极拳 (taiji-quan)                      - 深不可测 330/  193\n"+
"□太极神功 (taiji-shengong)                - 深不可测 332/18089\n"+
"  太玄功 (taixuan-gong)                    - 深不可测 278/37811\n"+
"  道学心法 (taoism)                        - 豁然贯通 150/    0\n"+
"  基本拳脚 (unarmed)                       - 深不可测 311/26426\n"+
"□五虎断门刀 (wuhu-duanmendao)             - 深不可测 201/ 2312\n"+
"  血刀刀法 (xue-dao)                       - 超凡入圣 438/48464\n"+
"□金刚瑜迦母拳 (yujiamu-quan)              - 超凡入圣 400/62140\n", this_object());
	return 1;
}
int do_hp()
{
message_vision("$N说： 我的基本状态如下：\n\n"+
"≡──────────────────────────────≡\n"+
"【 精 气 】  522/  522 (100%)   【 精 力 】  154 /  154 (+0)\n"+
"【 气 血 】 3011/ 3011 (100%)   【 内 力 】 5002 / 5002 (+0)\n"+
"【 食 物 】  191/  360          【 潜 能 】  19\n"+
"【 饮 水 】  150/  360          【 经 验 】  9138500\n"+
"≡──────────────────────────────≡\n", this_object());
}

int do_score()
{
message_vision("$N说： 我的基本状况如下：\n\n"+
"【旷世大侠】圣人逍遥门门主雪山派俗家弟子「福 星 高 照」冷枫(Top)\n"+
"\n"+
" 你是一位五十六岁九个月的男性人类，甲寅年一月一日辰时三刻生。\n"+
" 膂力：[ 57]  悟性：[ 51]  根骨：[ 46]  身法：[ 56]\n"+
"\n"+
" 你的师父是 葛伦布。             存款：二千零十四两黄金。\n"+
" 你还是个光棍。\n"+
"\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
"\n"+
" 食物：■■■■■■■■■■■■■□□□□□□□□□□□□\n"+
" 饮水：■■■■■■■■■■□□□□□□□□□□□□□□□\n"+
"\n"+
" 你到目前为止总共杀了 11831 个人，其中有 19 个是其他玩家。\n"+
"\n"+
" 你到目前为止总共死了 41 次了，其中有 29 次是非正常死亡。\n"+
"\n"+
" 正    气： 1744183791   潜    能：  19 ( 99%)   实战经验：  9138500\n"+
" 魅    力：       60     江湖阅历：   345593     江湖威望：       80\n"+
"\n", this_object());
	return 1;
}

