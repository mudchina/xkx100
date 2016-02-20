//Edited by fandog, 02/15/2000

inherit ITEM;
#include <ansi.h>


void create()
{
	set_name(HIY"虎撑"NOR, ({"hu cheng", "cheng"}));
	set("unit", "把");
//	set("no_get", 1);

	set("long", "这是一把郎中走街串巷摇着的虎撑。\n");
	setup();
}
