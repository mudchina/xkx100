#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

void create()
{
	set_name(HIY "黄骠马" NOR, ({ "huangbiaoma"}));
	set("race", "走畜");
	set("gender", "雄性");
	set("age", 2+random(3));
	set("long", "这是一匹黄骠骏马，全身金黄，没有一丝杂毛。\n"+
		"玩家可以骑上它去指定的地方(ride)。\n");
	set("ridable", 1);
	set("int", 30);
	set("qi", 300);
	set("max_qi", 300);
	set("jing", 100);
	set("max_jing", 100);
	set("shen_type", 0);
	set("combat_exp",50000);
	set("attitude", "peaceful");

	set_temp("apply/attack", 50);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 25);

	set("chat_chance", 4);
        set("chat_msg", ({
		HIY"黄骠马"NOR"低下头来，「奚奚嗦嗦」地嚼着干草。\n",
                HIY"黄骠马"NOR"抬头看了看你，继续埋下头吃它的夜草。\n",
        }) );

	setup();
	setup();
}
