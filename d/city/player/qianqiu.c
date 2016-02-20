// qianqiu.c
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("一心向佛", ({ "qianqiu"}));
	set("gender", "男性");
	set("class", "bonze");
	set("title", "轩辕教外务长老少林派第三十八代弟子");
	set("nickname", "酒肉穿肠过佛祖心中坐");
	set("age", 56);
	set("attitude", "friendly");

	set("kar", 30);
	set("per", 26);
	set("int", 24);
	set("dex", 11);
	set("con", 24);
	set("str", 26);
	set("weiwang", 80);
	create_family("少林派" , 38, "弟子");
	setup();
	carry_object(CLOTH_DIR"seng-cloth")->wear();
        carry_object(CLOTH_DIR"seng-shoe")->wear();
}
