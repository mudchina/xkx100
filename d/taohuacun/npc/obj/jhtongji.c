#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name(YEL"叫化童鸡"NOR, ({"jhtongji"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("long", "一只被烤得流油，香味扑鼻的叫化鸡。\n");
                set("unit", "只");
                set("value", 120);
                set("food_remaining", 1);
                set("food_supply", 100);
                set("cook_msg", "
$N把嫩母鸡宰杀褪洗干净后，肋开取 出内脏，经用山奈、八角、
酱油、绍酒、白糖、精盐、味精、葱段、姜丝和成 的卤汁腌渍，
再逐层包上猪网油、荷叶、玻璃纸，用细麻绳扎好，最外面再包 
上和好的酒坛泥和泥加料酒、精盐，烘烤两个时辰，[扌盍]去 
泥包，蘸花椒盐、辣酱油佐食。\n\n"
		);                
        }
}
