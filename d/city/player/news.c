// fall.c
#include <ansi.h>
inherit NPC;
int do_hp();
int do_score();
int do_skills();
void create()
{
	set_name("步惊云", ({ "news"}));
	set("gender", "男性");
	set("long","早年游侠江湖，酷爱交友和解谜，曾创下三天两夜不眠挖泥
的超级记录，为人偶尔亦会整人，虽有点放荡不羁，但常
真诚帮人。虽其貌不惊人，但其发展新手的速度可谓是
前无古人后无来者。早年出身丐帮当小乞丐，而后出家全真，
转而陪伴东方不败绣花，最后于凌霄之颠，一览天下小。\n");
	set("title", HIW"圣人"HIG"明教天字门教众"NOR"凌霄城掌门大师兄"NOR);
	set("nickname", HIR"不哭死神"NOR);
	set("age", 18);
	set("class", "sword");
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 30);
	set("int", 42);
	set("dex", 41);
	set("con", 42);
	set("str", 42);
	set("weiwang", 10);
	set("shen", 8623);
	set("combat_exp", 2995735);
	set("PKS", 1);
	set("MKS", 1968);

	set("max_jing", 250);
	set("jing", 250);
	set("max_qi", 1092);
	set("qi", 1092);
	set("max_jingli", 0);
	set("jingli", 0);
	set("max_neili", 3650);
	set("neili", 3650);
	set("meili", 0);
	set("env/no_teach", "1");

	set_skill("literate", 200);
	set_skill("taoism", 99);
	set_skill("dodge", 199);
	set_skill("force", 219);
	set_skill("parry", 174);
	set_skill("unarmed",20);
	set_skill("sword", 298);
	set_skill("strike", 100);
	set_skill("bingxue-xinfa", 990);
	set_skill("snow-strike", 12);
	set_skill("snowstep", 226);
	set_skill("taixuan-gong", 251);
	set_skill("xueshan-sword", 304);

	map_skill("force", "bingxue-xinfa");
	map_skill("dodge", "snowstep");
	map_skill("parry", "xueshan-sword");
	map_skill("sword", "xueshan-sword");
	map_skill("unarmed","taixuan-gong");
	map_skill("strike","snow-strike");
	set("inquiry", ([
		"hp"    : (: do_hp :),
		"score" : (: do_score :),
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("明教",35, "弟子");
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}

int do_skills()
{
message_vision("$N说： 我所有的基本武功如下：\n"+

"≡─────────────────────────────────≡\n"+
"□冰雪心法 (bingxue-xinfa)                 - 神乎其技 299/ 1464\n"+
"  基本轻功 (dodge)                         - 融会贯通 199/   73\n"+
"  基本内功 (force)                         - 炉火纯青 219/ 9497\n"+
"  读书写字 (literate)                      - 融会贯通 200/  882\n"+
"  基本招架 (parry)                         - 驾轻就熟 174/   19\n"+
"□飞雪映梅掌 (snow-strike)                 - 毫不足虑  12/   34\n"+
"□梅雪飘香 (snowstep)                      - 了然于胸 226/10062\n"+
"  基本掌法 (strike)                        - 平淡无奇 100/    0\n"+
"  基本剑法 (sword)                         - 神乎其技 298/53415\n"+
"□太玄功 (taixuan-gong)                    - 豁然贯通 251/    0\n"+
"  道学心法 (taoism)                        - 半生不熟  99/    0\n"+
"  基本拳脚 (unarmed)                       - 不足挂齿  20/    2\n"+
"□雪山剑法 (xueshan-sword)                 - 出神入化 304/40829\n"+
"≡─────────────────────────────────≡\n", this_object());
	return 1;
}
int do_hp()
{
message_vision("$N说： 我的基本状态如下：\n\n"+
"≡──────────────────────────────≡\n"+
"【 精 气 】  250/  250 (100％)   【 精 力 】    0 /    0 (+0)\n"+
"【 气 血 】 1092/ 1092 (100％)   【 内 力 】 3650 / 3650 (+0)\n"+
"【 正 气 】    8623              【 体 力 】   50 /   50\n"+
"【 食 物 】  256/  300           【 潜 能 】  0\n"+
"【 饮 水 】  179/  300           【 经 验 】  2995735\n"+
"≡──────────────────────────────≡\n", this_object());
	return 1;
}

int do_score()
{
message_vision("$N说： 我的基本状况如下：\n\n"+
"【 剑  士 】明教天字门教众凌霄城掌门大师兄「不哭死神」步惊云(News)\n\n"+
" 你是一位十九岁五个月性格普通的男性人类，甲寅年一月一日辰时三刻生。\n"+
" 膂力[20/ 30]  悟性[30/ 50]  根骨[16/ 37]  身法[14/ 33]  耐力[24/ 41]\n"+
" 灵性[25/ 34]  福缘[30/ 30]  胆识[22/ 22]  定力[15/ 15]  容貌[20/320]\n\n"+
" 你的师父是 白自在。        你还是个光棍。\n"+
" 存款：二百三十三两黄金七十七两白银二十九文铜钱。\n\n"+
" <精>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n"+
" <气>  ■■■■■■■■■■■■■■■■■■■■■■■■■\n\n"+
" 食物：■■■■■■■■■■■■■■■■■■■■■□□□□\n"+
" 饮水：■■■■■■■■■■■■■■■□□□□□□□□□□\n\n"+
" 你到目前为止总共杀了 2115 个人，其中有 1 个是其他玩家。\n"+
" 你到目前为止总共死了 25 次了，其中有 19 次是非正常死亡。\n\n"+
" 正    气：     8623     潜    能：  20 ( 99%)   实战经验：  2959269\n"+
" 魅    力：       60     江湖阅历：    22994     江湖威望：       30\n"+
"\n", this_object());
	return 1;
}

