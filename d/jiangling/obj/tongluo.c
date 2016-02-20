//Edited by fandog, 02/15/2000
#include <ansi.h>
inherit ITEM;
int do_play(string arg);

//void setup()
//{}

void init()
{
        add_action("do_qiao", "qiao");
}

void create()
{
        set_name(HIY"铜锣"NOR, ({"tongluo"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "面");
                set("long", "这是一面武汉产的铜锣。你可以敲敲(qiao)它。\n");
                set("value", 100);
        }
//        setup();
}

int do_qiao(string arg)
{
        if (!id(arg))
                return notify_fail("你要敲什么？\n");
        switch( random(2) ) {
                case 0:
                        say(this_player()->name() + "敲了敲铜锣，镗～～～，把你吓了一跳。\n");
			write(this_player()->name() + "敲了敲铜锣，镗～～～，把旁边的人吓了一跳。\n");

                        break;
                case 1:
                        say(this_player()->name() + "使劲敲敲铜锣：咣～～～，真是震耳欲聋。\n");
			write(this_player()->name() + "使劲敲敲铜锣：咣～～～，真是震耳欲聋。\n");

                        break;
        }
        return 1;
}

