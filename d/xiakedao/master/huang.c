#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("黄药师", ({"huang-yaoshi", "huang", "yaoshi"}));
    set("title", "桃花岛主");
    set("nickname", HIY "东邪" NOR );
    set("gender", "男性");
    set("age", 42);
    set("long", 
        "他就是桃花岛主。行事好恶全由己心，因此被人称作「东邪」。\n");
    set("attitude", "peaceful");
    set("class", "scholar");
	
    set("str", 21);
    set("int", 30);
    set("con", 26);
    set("dex", 30);

    set("qi", 3000);
    set("max_qi", 3000);
    set("jing", 3000);
    set("max_jing", 3000);
    set("neili", 3500);
    set("max_neili", 3500);
    set("jiali", 100);
	
    set("combat_exp", 1500000);
    set("score", 0);
	 
    set_skill("force", 150);             // 基本内功
    set_skill("bibo-shengong", 150);     // 碧波神功
    set_skill("claw", 150);              // 基本爪法
    set_skill("hand", 150);              // 基本手法
    set_skill("finger", 170);            // 基本指法
    set_skill("tanzhi-shentong", 170);   // 弹指神通
    set_skill("unarmed", 180);           // 基本拳脚
    set_skill("strike", 180);            // 基本拳脚
    set_skill("luoying-zhang", 180);     // 落英神剑掌
    set_skill("xuanfeng-leg", 180);      // 旋风扫叶腿
    set_skill("dodge", 150);             // 基本躲闪
    set_skill("anying-fuxiang", 120);    // 暗影浮香
    set_skill("parry", 150);             // 基本招架
    set_skill("sword", 200);             // 基本剑法
    set_skill("luoying-shenjian", 200);  // 落英神剑
    set_skill("yuxiao-jian", 200);       // 玉箫剑法
    set_skill("lanhua-shou", 200);       // 兰花拂穴手
    set_skill("qimen-wuxing",150);       // 奇门五行
    set_skill("count",150);              // 阴阳八卦
    set_skill("literate",150);           // 读书识字
	
    map_skill("force"  , "bibo-shengong");
    map_skill("finger" , "tanzhi-shentong");
    map_skill("hand"   , "lanhua-shou");
    map_skill("unarmed", "luoying-zhang");
    map_skill("strike" , "xuanfeng-leg");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("parry"  , "luoying-shenjian");
    map_skill("sword"  , "yuxiao-jian");

    create_family("桃花岛", 1, "岛主");
    setup();

    carry_object("/clone/misc/cloth")->wear();
    carry_object("/kungfu/class/taohua/obj/yuxiao")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	object *obj, me=this_object();
	int i;

	obj = all_inventory(environment(me));
        command("say  一灯大师，您贵位一国天子却出家为僧，此句深藏身与名，您必深得其意。");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="yideng-dashi")
                {
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                }
	}
        return;
}

