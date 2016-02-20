// qiao.c 樵夫

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("樵夫", ({ "qiao fu", "qiao" }));
	set("title",  "大理国大将军" );
	set("long", 
"他就是大理国的原大将军，一灯大师的四大弟子之一。
左手提着一捆松柴，右手握着一柄斧头，但见他容色豪
壮，神态虎虎，举手迈足间似是大将军有八面威风。若
非身穿粗布衣裳而在这山林间樵柴，必当他是个叱咤风
云的统兵将帅。\n");
	set("gender", "男性");
	set("age", 45);
	set("class", "officer");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 20);
	set("str", 30);
	set("int", 30);
	set("con", 35);
	set("dex", 30);

	set("max_qi", 1500);
	set("max_jing", 500);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);
	set("combat_exp", 500000);
	set("score", 10000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("cuff", 100);
        set_skill("strike", 100);
        set_skill("axe", 100);
        set_skill("finger", 100);
	set_skill("kurong-changong", 100);
        set_skill("tiannan-step", 150);
        set_skill("jinyu-quan", 150);
        set_skill("wuluo-zhang", 150);
        set_skill("duanyun-fu", 150);
        set_skill("sun-finger", 150);
	set_skill("literate", 100);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");
	map_skill("finger", "sun-finger");
	map_skill("cuff", "jinyu-quan");
	map_skill("strike", "wuluo-zhang");
	map_skill("parry", "sun-finger");
	map_skill("axe", "duanyun-fu");
	prepare_skill("cuff", "jinyu-quan");
	prepare_skill("strike", "wuluo-zhang");
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(: perform_action, "sword.jingtian" :),	
		(: perform_action, "finger.qiankun" :),			
		(: exert_function, "powerup" :),		
		(: exert_function, "recover" :),
		(: exert_function, "regenerate" :),
	}) );

        set("inquiry", ([
                "一灯大师"   : "师父他老人家在上面。\n",
                "段智兴"     : "那是我师父俗世的名讳。\n",
                "刘瑛姑"     : "她是我师父俗世的妃子。\n",
        ]) );

        set("chat_chance", 3);
        set("chat_msg", ({
"那樵子唱道：
    “城池俱坏，英雄安在？云龙几度相交代？想兴衰，苦为怀。唐家才起隋家败，世态
有如云变改。疾，也是天地差！迟，也是天地差！”\n",
"那樵子唱道：
    “天津桥上，凭栏遥望，舂陵王气都凋丧。树苍苍，水茫茫，云台不见中兴将，千古
转头归灭亡。功，也不久长！名，也不久长！”\n",
"那樵子唱道：
    “城池俱坏，英雄安在？云龙几度相交代？想兴衰，苦为怀。唐家才起隋家败，世态
    “峰峦如聚，波涛如怒，山河表里潼关路。望西都，意踟蹰。伤心秦汉经行处，宫阙
万间都做了土。兴，百姓苦！亡，百姓苦！”\n",
"那樵子唱道：
    “青山相待，白云相爱。梦不到紫罗袍共黄金带。一茅斋，野花开，管甚谁家兴废谁
成败？陋巷单瓢亦乐哉。贫，气不改！达，志不改！”\n",
"隐隐听得那樵子又在唱曲，甚么
    “……当时纷争今何处？赢，都变作土！输，都变作土！”\n",
        }) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/kungfu/class/dali/obj/axe")->wield();
	add_money("silver", 50);

	create_family("大理段家",25,"弟子");
}

