// yuzhenzi.c

#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

void create()
{
	set_name("玉真子", ({ "yuzhen zi", "yuzhen" }));
	set("gender", "男性");
	set("title", "铁剑门掌门人");
	set("nickname", HIC"护国真人"NOR);
	set("age", 44);
	set("str", 25);
	set("dex", 20);
	set("long", "这是一位颇有仙风道骨的潇洒全真，手握长剑，目视前方。\n"+
	"他就是木桑道人的师弟，在西藏寻得本门铁剑，成为本门掌门，尽管如此，\n"+
	"他的行止确十分不端。\n");
	set("combat_exp", 900000);
	set("score", 10000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	set("jing", 1000);
	set("max_jing", 1000);
	set("qi", 3000);
	set("max_qi", 3000);

	set_skill("sword", 150);
	set_skill("force", 90);
	set_skill("unarmed", 90);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("huashan-jianfa", 150);
	set_skill("shenxing-baibian", 150);
	map_skill("whip",  "huashan-jianfa");
	map_skill("parry", "huashan-jianfa");
	map_skill("dodge", "shenxing-baibian");

	set("neili", 1500); 
	set("max_neili", 1500);
	set("jiali", 100);
	setup();
        carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 2);
}

