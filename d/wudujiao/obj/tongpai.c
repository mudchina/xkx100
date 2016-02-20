// tongpai.c
#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_read","see");
}

void create()
{
               set_name("铜牌", ({"tongpai" }));

                set("unit", "面");
                set("long", "这是一面四四方方的铜牌,上面刻着:“千蛛万毒”四个
大字。\n铜牌背面好象雕着一些细细的花纹，需要仔细看(see)才能勉强看清楚。\n");
                set("value", 0);
              set("no_drop", "这样东西不能离开你。\n");
              set_weight(200);

        setup();
}

int do_read(string arg)
{
        return notify_fail("                           \n
                                    ^                 \n
                                 @@^ ^     ^          \n
                                  ^ ^ ^   ^ ^ @@@     \n
                               @@@@^ ^ ^ ^ ^ ^        \n
                                ^ ^ ^ ^ ^ ^ ^ ^       \n
                               ^ ^ ^ ^ ^ ^ ^ ^ ^       \n
                              ^ ^ ^ ^O^ ^O^ ^O^ ^       \n
                             ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^       \n
                            ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^      \n
                           ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^    \n
");
}

