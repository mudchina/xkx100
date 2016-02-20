// xiaoshami.c
inherit NPC;
#include <ansi.h>
void create()
{
	set_name("小沙弥", ({"xiao shami","shami",}));
	set("long",
	"他是本寺小沙弥。\n");
	set("gender", "男性");
	set("age", 12);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("class", "bonze");

	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);

	set("max_qi", 150);
	set("max_jing", 100);
	set("neili", 150);
	set("max_neili", 150);

	set("combat_exp", 2000);
	set("score", 1000);

	set_skill("force", 30);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);

	setup();

	carry_object("/d/shaolin/npc/obj/dao-cloth.c")->wear();
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
	mapping myfam;

	myfam = (mapping)ob->query("family");
	if( (myfam["master_id"] == "yideng dashi") &&
		! environment(this_object())->query("exits/out"))
	{
message_vision(HIY"小沙弥对$N说：“你回来了。去见师父吧。”说着打开后门。\n"NOR, ob);
		environment(this_object())->set("exits/out","/d/heizhao/zhulin1");
	}
	return;
}

int accept_object(object who, object ob)
{
	if ( !who || environment(who) != environment() ) return 0;
	if ( !objectp(ob) ) return 0;
	if ( !present(ob, who) ) return notify_fail("你没有这件东西。\n");

	if ( (string)ob->query("id") != "huangbu xiaonan")
		return notify_fail("小沙弥不想要这件东西。\n");
	environment(this_object())->set("exits/out","/d/heizhao/zhulin1");
message_vision(HIY"小沙弥点了点头，把禅院后门打开来。\n"NOR, who);
	return 1;
}

