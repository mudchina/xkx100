// fang.c 

inherit NPC;
//inherit F_SKILL;

void create()
{
	set_name("方人智", ({ "fang renzhi", "fang", "renzhi" }));
	set("gender", "男性");
	set("age", 20);
	set("long", "他就是「青城派」年轻一代弟子，以智计为师尊喜爱。\n");

	set("combat_exp", 50000);
	set("shen_type", -1);

	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("strike", 50);
	set_skill("unarmed", 50);
	set_skill("force", 50);
	set_skill("bixie-sword", 50);
	set_skill("songfeng-jian", 50);
	set_skill("chuanhua", 50);
	set_skill("wuying-leg", 50);
	set_skill("cuixin-strike", 50);
	set_skill("qingming-xuangong", 50);
	map_skill("force", "qingming-xuangong");
	map_skill("unarmed", "wuying-leg");
	map_skill("strike", "cuixin-strike");
	map_skill("dodge", "chuanhua");
	map_skill("parry", "bixie-sword");
	map_skill("sword", "songfeng-jian");
	prepare_skill("unarmed", "wuying-leg");
	prepare_skill("strike", "cuixin-strike");
	create_family("青城派", 6, "弟子");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/d/wudang/obj/bluecloth")->wear();
	add_money("gold", 2);
}
