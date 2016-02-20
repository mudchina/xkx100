// mai.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("麦鲸", ({ "mai jing", "mai", "jing" }));
	set("title", HIC"巨鲸帮帮主"NOR);
	set("long", 
"他从七八岁起，便常钻到海底摸鱼捉蟹，水性极高，便一炷香不
出水面，也淹他不死。\n");

	set("gender", "男性");
	set("age", 52);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("per", 20);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 600);
	set("max_jing", 600);
	set("neili", 600);
	set("max_neili", 600);
	set("combat_exp", 70000);
	set_skill("parry", 60);
	set_skill("unarmed", 60);
	set_skill("changquan", 60);
	map_skill("parry", "changquan");
	map_skill("unarmed", "changquan");

	setup();
	carry_object("/clone/cloth/cloth")->wear();
}

