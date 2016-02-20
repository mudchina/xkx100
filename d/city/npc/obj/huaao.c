//Cloth :huaao.c

#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("绣花短袄", ({ "hua ao", "cloth"}) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一套绣花的的布袄，略小了点，好象是童装。\n");
		set("unit", "套");
		set("value", 100);
		set("material", "cloth");
		set("armor_prop/armor", 1);
		set("kid_only", 1);
		set("female_only", 1);
	}
	setup();
}
