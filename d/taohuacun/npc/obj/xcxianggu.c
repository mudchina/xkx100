#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIC "鲜菜香菇" NOR, ({"xcxianggu"}));
        set_weight(500);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盘清淡，但囗味却还不错的鲜菜香菇。\n");
                set("unit", "盘");
                set("value", 50);
                set("food_remaining", 3);
                set("food_supply", 20);
                set("cook_msg", "
$N把香菇用冷水略冲洗干净後，用开水发开。切成条。 
然后冷锅起油，加入少许蚝油略炒，加入青菜，翻炒至
青菜变色，加入切好的香菇，略翻炒後，加盐调囗味，
另用发香菇的水，调开少许芡粉，勾芡後待汤汁收浓。\n\n"
		);                
        }
}
