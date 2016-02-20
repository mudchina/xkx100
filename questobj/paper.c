// paper.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"华山论剑"HIR"英雄帖"NOR, ({"yingxiong tie", "tie"}));
	set_weight(100);
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "张");
		set("long",
"这是武林盟主邀约公平子参加华山论剑比武大会，充任比武裁判的请帖。\n");
		set("material", "paper");
	}
}

