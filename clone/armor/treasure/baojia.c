// baojia.c

#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_UNIQUE;

void create()
{
	set_name(HIY "��˿����" NOR, ({ "bao jia", "jia" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("no_drop","��������/�����˵ģ�Ҳ���ܸ����ˡ�");
		set("value", 50000);
		set("material", "gold");
		set("armor_prop/armor", 200);
	}
	setup();
}

void init()
{
	if(uptime() < 300) destruct(this_object());
}