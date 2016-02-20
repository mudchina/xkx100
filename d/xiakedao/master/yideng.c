// yideng.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
    set_name("一灯大师", ({"yideng-dashi", "dashi", "yideng"}));
    set("nickname", HIG "南帝" NOR );
    set("gender", "男性");
    set("age", 52);
    set("long", 
        "他就是号称「南帝」的一灯大师，俗名段智兴，现已逊位为僧。\n"
        "大师一生行善，积德无穷。\n");
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
    set_skill("finger", 170);            // 基本指法
    set_skill("dodge", 150);             // 基本躲闪
    set_skill("parry", 150);             // 基本招架
    set_skill("six-finger", 200);        // 六脉神剑
    set_skill("taixuan-gong", 200);      // 太玄神功
    set_skill("lingxu-bu", 200);         // 凌虚步
    set_skill("literate",150);           // 读书识字
	
    map_skill("force"  , "taixuan-gong");
    map_skill("finger" , "six-finger");
    map_skill("dodge"  , "lingxu-bu");
    map_skill("parry"  , "six-finger");

    prepare_skill("finger", "six-finger");

    create_family("大理段家", 17, "弟子");
    setup();

    carry_object("/clone/misc/cloth")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob=this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 2, ob);
        }
}

void greeting(object ob)
{
	object *obj, me=this_object();
	int i;

	obj = all_inventory(environment(me));
//一灯大师哈哈大笑，对着黄药师拱了拱手道：老爷子过奖了!
        command("nali huang");
        command("say 劲力内含，发之无形，伤人与不觉之中。");
	for(i=0; i<sizeof(obj); i++)
	{
		if( obj[i]->query("id")=="huang-yaoshi")
                {
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                    COMBAT_D->do_attack(me, obj[i], me->query_temp("weapon"), 0);
                }
	}
        return;
}

