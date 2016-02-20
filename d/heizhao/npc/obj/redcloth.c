// item: redcloth.c

inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIR"红布"NOR, ({"hong bu", "bu"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", 
"这是一块红布，上面写着一行字道：“把此布交给渔翁。
上山之后将黄色布囊交给小沙弥。”\n");
                set("unit", "块");
                set("value", 1);
        }
}

