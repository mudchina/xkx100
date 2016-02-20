// rewj_sword
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(HIY"一阵云烟"NOR, ({ "cigar", "sword" }));
	set_weight(6000);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("value", 2000);
		set("material", "steel");
		set("wield_msg", "$N抽了$n，惨然一笑，接着长叹一声，从裤兜里取出个白玉磁瓶，倒出菩提子吧唧吧唧啃了起来。\n");
		set("unwield_msg", "$N一声长叹：人生如梦，梦如$n，烟如雾，雾如水蒸气，水蒸气如那个屁啊。\n");
	}
	init_sword(30);
	setup();
}

