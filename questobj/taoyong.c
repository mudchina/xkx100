// taoyong.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"陶俑"NOR, ({"tao yong", "tao","yong"}));
	set("long", "这是一个才出土不久陶俑。\n");
	set("taskobj", 1);
	set("unit", "个");
	set("value", 0);
	set("weight", 10);
}

