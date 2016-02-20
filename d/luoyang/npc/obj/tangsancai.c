// tangsancai.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG"唐"HIY"三"HIC"彩"NOR, ({"tang sancai", "tang"}));
	set("long", "这是一尊唐三彩马。\n");
	set("unit", "尊");
	set("value", 50000);
	set("weight", 100);
}

