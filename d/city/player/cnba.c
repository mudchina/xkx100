// cnba.c
#include <ansi.h>
inherit NPC;
int do_skills();
void create()
{
	set_name("球王", ({ "cnba"}));
	set("gender", "男性");
        set("long","本潭最早的玩家之一。
此人性格坚忍，早年乃武当名门弟子，后叛加入丐帮。
曾在江湖肆意屠戮多年，引发轩然大波。那段杀气弥漫的日子，
是所有老玩家秋天时一抹寒凉的回忆。其默默练功的执著与坚韧，
仍是值得称许的武林风范。\n");
	set("title", HIR"内阁大学士"NOR"丐帮第二十代弟子");
	set("age", 61);
	set("class", "beggar");
	set("attitude", "friendly");

	set("kar", 27);
	set("per", 22);
	set("int", 22);
	set("dex", 15);
	set("con", 20);
	set("str", 24);
	set("weiwang", 70);
	set("shen", 154468);
	set("combat_exp", 1771911);
	set("PKS", 53);
	set("MKS", 1716);

	set("max_jing", 625);
	set("jing", 625);
	set("max_qi", 1948);
	set("qi", 1948);
	set("max_jingli", 693);
	set("jingli", 693);
	set("max_neili", 2790);
	set("neili", 2790);
	set("meili", 60);
	set("env/no_teach", "1");

	set_skill("literate", 170);
	set_skill("force", 251);
	set_skill("unarmed",7);
	set_skill("parry", 160);
	set_skill("dodge", 250);
	set_skill("sword", 250);
	set_skill("cuff", 99);
	set_skill("hand", 99);
	set_skill("claw", 195);
	set_skill("strike", 99);
	set_skill("taoism", 149);
	set_skill("hubo", 99);
	set_skill("club", 2);
	set_skill("whip", 2);
	set_skill("throwing", 14);
	set_skill("array", 23);
	set_skill("staff", 4);
	set_skill("finger", 78);
	set_skill("stealing", 99);
	set_skill("checking", 74);
	set_skill("blade", 5);
	set_skill("begging", 42);
	set_skill("qimen-wuxing", 100);

	set_skill("shenxing-baibian", 82);
	set_skill("lingboweibu", 5);
	set_skill("taiji-jian", 247);
	set_skill("qiankun-danuoyi", 30);
	set_skill("taiji-quan", 106);
	set_skill("shenkong-xing", 4);
	set_skill("liangyi-jian", 10);
	set_skill("taiji-shengong", 193);
	set_skill("tiyunzong", 191);
	set_skill("kongming-quan", 89);
	set_skill("jiuyin-baiguzhao", 174);

	map_skill("force", "taiji-shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	map_skill("claw","jiuyin-baiguzhao");
	map_skill("unarmed","taiji-quan");
	prepare_skill("claw","jiuyin-baiguzhao");

	set("inquiry", ([
		"skill" : (: do_skills :),
		"武功"  : (: do_skills :),
	]));

	create_family("丐帮", 20, "弟子");
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
	carry_object(WEAPON_DIR"changjian")->wield();
}

int do_skills()
{
message_vision("$N说： 我所有的基本武功如下：\n"+
"  基本阵法 (array)                         - 初窥门径  23/    0\n"+
"  叫化绝活 (begging)                       - 半生不熟  42/    0\n"+
"  基本刀法 (blade)                         - 初学乍练   5/    0\n"+
"  道听途说 (checking)                      - 马马虎虎  74/    0\n"+
"  基本爪法 (claw)                          - 一代宗师 195/    0\n"+
"  基本棍法 (club)                          - 初学乍练   2/    0\n"+
"  基本拳法 (cuff)                          - 驾轻就熟  99/    0\n"+
"  基本轻功 (dodge)                         - 深不可测 250/    0\n"+
"  基本指法 (finger)                        - 马马虎虎  78/    0\n"+
"  基本内功 (force)                         - 深不可测 251/    0\n"+
"  基本手法 (hand)                          - 驾轻就熟  99/    0\n"+
"  左右互搏 (hubo)                          - 已有小成  99/    0\n"+
"□九阴白骨抓 (jiuyin-baiguzhao)            - 登峰造极 174/    0\n"+
"  空明拳 (kongming-quan)                   - 驾轻就熟  89/    0\n"+
"  两仪剑法 (liangyi-jian)                  - 初学乍练  10/    0\n"+
"  凌波微步 (lingboweibu)                   - 初学乍练   5/    0\n"+
"  读书写字 (literate)                      - 举世无双 170/    0\n"+
"  基本招架 (parry)                         - 登峰造极 160/    0\n"+
"  乾坤大挪移 (qiankun-danuoyi)             - 粗通皮毛  30/    0\n"+
"  奇门五行 (qimen-wuxing)                  - 心领神会 100/    0\n"+
"  身空行 (shenkong-xing)                   - 初学乍练   4/    0\n"+
"  神行百变 (shenxing-baibian)              - 驾轻就熟  82/    0\n"+
"  基本杖法 (staff)                         - 初学乍练   4/    0\n"+
"  妙手空空 (stealing)                      - 驾轻就熟  99/    0\n"+
"  基本掌法 (strike)                        - 驾轻就熟  99/    0\n"+
"  基本剑法 (sword)                         - 深不可测 250/    0\n"+
"□太极剑法 (taiji-jian)                    - 深不可测 247/    0\n"+
"□太极拳 (taiji-quan)                      - 出类拔萃 106/    0\n"+
"□太极神功 (taiji-shengong)                - 一代宗师 193/    0\n"+
"  道学心法 (taoism)                        - 豁然贯通 149/    0\n"+
"  基本暗器 (throwing)                      - 初学乍练  14/    0\n"+
"□梯云纵 (tiyunzong)                       - 一代宗师 191/    0\n"+
"  基本拳脚 (unarmed)                       - 初学乍练   7/    0\n"+
"  基本鞭法 (whip)                          - 初学乍练   2/    0\n", this_object());   

	return 1;
}

