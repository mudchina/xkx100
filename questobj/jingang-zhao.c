// jingang-zhao.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIY"金刚"HIB"罩"NOR, ({ "jingang zhao", "zhao" }));
	set_weight(500);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long","这是一件金光闪闪的袈裟，通体用天山雪蚕丝织成，坚韧\n无比刀剑不能伤。此袈裟数百年前由达摩老祖携入中原，邪魔见之辟易，\n乃是佛家无上降魔法宝。\n");
		set("material", "cloth");
		set("unit", "件");
		set("wear_msg", HIY "只听「哗」的一声，$N展开一件金光闪闪的袈裟披在身上。\n瞬时间日月为之失色，瑞气千条，祥云朵朵，一派庄严气象。\n" NOR);
		set("remove_msg", HIY "$N将金刚罩从身上脱了下来，折叠成小小的一团。\n" NOR);
		set("armor_prop/armor",100);
	}
	setup();
}
