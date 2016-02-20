// cao.c
inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIG"通天草"NOR, ({"tongtian cao","cao"}));
        set("unit", "根");
        set("long", "这是一支碧绿小草，细细长长的。\n");
        setup();
}
