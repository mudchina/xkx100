#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("礁石", ({"jiao shi", "stone", "shi"}));
        set("unit", "块");
        set("long", "这是露出海面的礁石，只有容得下一个人站住。\n");
	set_temp("apply/yinshen",1);
        set("value", 1000);
        setup();
}
