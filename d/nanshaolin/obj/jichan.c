// Obj: /d/nanshaolin/obj/jichan.c
// Last Modified by winder on May. 29 2001

inherit NPC;
void create()
{
	set_name("寂禅石人", ({ "jichan shiren", "jichan", "shiren" }));
	set("long", "年代久远已无法看清他当年之相貌，\n"
		"他生的异常结实，浑身筋骨犹如铁铸一般。\n");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("age", 100);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_qi", 1200);
	set("max_jing", 1000);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 1200000);
	set("score", 200);
	set_skill("force", 140);
	set_skill("qianye-hand",140);
	set_skill("yijinjing", 140);
	set_skill("dodge", 140);
	set_skill("yiwei-dujiang", 140);
	set_skill("hand", 140);
	set_skill("parry", 140);
	set_skill("buddhism", 140);
	map_skill("force", "yijinjing");
	map_skill("dodge", "yiwei-dujiang");
	map_skill("hand", "qianye-hand");
	map_skill("parry", "qianye-hand");
	prepare_skill("hand", "qianye-hand");
	setup();
}
#include "chan.h"
