// miaoruolan.c 苗若兰

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("苗若兰", ({ "miao ruolan", "ruolan", "miao" }) );
	set("gender", "女性");
	set("age", 17);
	set("long","她是天下第一高手，“打遍天下无敌手”的“金面佛”苗人凤之女。只是自小家教，不习武功。\n");
	set("attitude", "friendly");
	set("str", 15);
	set("int", 15);
	set("con", 19);
	set("dex", 17);
	set("per", 34);
	set("combat_exp", 2000);

	set("chat_chance", 10);
	set("chat_msg", ({
		"苗若兰幽幽地道：当年那个可怜的小男孩现在也不知怎么样了？\n",
		"苗若兰皱了皱秀眉：爹爹怎么还没上山？\n",
        }) );

	setup();
	carry_object(CLOTH_DIR"diaopi")->wear();
}
