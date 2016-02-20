// singleblue.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("细胳膊鹿", ({ "singleblue" }));
	set("title", HIM"电视台秘书"NOR);
	set("shen_type", 1);

	set("gender", "女性" );
	set("long", @LONG
细胳膊鹿懒得理你，继续埋头写作业。
LONG);
	set("nickname", HIW"脑子有小包"NOR);
	set("age", 20);
	set("per", 30);
	set("attitude", "friendly");		
        set("no_get", "1");
	set("env/no_teach", "1");

	set("inquiry", ([
	]));                 

	set("combat_exp", 1000000);
	setup();

	carry_object(CLOTH_DIR"female-cloth")->wear();
        carry_object(CLOTH_DIR"female-shoe")->wear();
}