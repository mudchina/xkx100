// wuchangyi.c

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name(BLK"乌蚕衣"NOR, ({ "wucan yi", "cloth" }) );
	set_weight(5000);
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "silk");
		set("value", 0);
		set("armor_prop/armor", 0);
		set("long",
"这一件刀枪不入的宝衣，是用大雪山的上乌蚕蚕丝织成的。整
件乌蚕衣只是两块料子，剪刀也剪不烂，只得前一块、后一块
的扣在一起。");
	}
	setup();
}

