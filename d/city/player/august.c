// august.c
#include <ansi.h>

inherit NPC;
void create()
{       set_name("叶竹雪", ({ "august"}));
	set("gender", "男性");
	set("class", "fighter");
	set("title", HIG"进士明教"NOR"天字门教众"HIR"明教使者"NOR);
	set("nickname", HIM"痞子二人组之痞子耍☆痞"NOR);
	set("age", 17);
	set("attitude", "friendly");

	set("kar", 19);
	set("per", 26);
	set("int", 20);
	set("dex", 20);
	set("con", 20);
	set("str", 20);
	set("weiwang", 80);
	setup();
	carry_object(CLOTH_DIR"male-cloth")->wear();
        carry_object(CLOTH_DIR"male-shoe")->wear();
}
