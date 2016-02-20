// zizhuxiao.c 紫竹箫

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(MAG "紫竹箫" NOR, ({"zizhu xiao", "xiao"}) );
	set_weight(1000);
	if ( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "此箫用紫竹制成，长约三尺有余。。\n");
		set("value", 600);
		set("unit", "支");
 		set("wield_msg","$N漫不经心的把$n握在手上。\n");
		set("unwield_msg", "$N放下手里的$n。\n");
	}
	init_sword(3);
	setup();
}
