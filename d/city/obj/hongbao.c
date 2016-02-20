// hongbao.c 红包
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIR"红包"NOR, ({ "red bag", "hong bao", "bao" }));
	set_weight(500);
	set_max_encumbrance(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个精制的红纸袋，边上有烫金的花纹，用来装贺仪礼金正合适。\n");
		set("value", 1000);
	}
}

int is_container() { return 1; }
