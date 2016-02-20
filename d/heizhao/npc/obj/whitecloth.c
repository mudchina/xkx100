// item: whitecloth.c

inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIW"白布"NOR, ({"bai bu", "bu"}));
        set_weight(80);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", 
"这是一块白布，上面绘着一张地图，图旁注着两行字道：“依图
中所示路径而行，路尽处系一大瀑布，旁有茅舍。到达时拆红色
布囊。”\n");
                set("unit", "块");
                set("value", 1);
        }
}

