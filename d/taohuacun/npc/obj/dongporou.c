
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED"东坡肉"NOR, ({"dongporou"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一碗香喷喷的东坡肉，用文火煨肥猪肉而成，
苏东坡在牧守杭州时看到民间吃肉而烧制不得法，遗惠此法至千年以下。\n");
                set("unit", "碗");
                set("value", 120);
                set("food_remaining", 10);
                set("food_supply", 100);
                set("cook_msg", "
$N将净猪五花肋肉切方形肉块，下沸水锅中稍煮。然后在大砂锅中铺上
葱和姜块，下入煮过的猪肉，加调料盖好锅盖，并用纱纸封缝。将砂锅
置旺火上，烧开后改用微火焖二小时，把肉块翻身，再加盖密封，用微
火焖二小时，把肉块翻至酥烂，倒入陶罐中再用旺火蒸。\n\n"
		);                
        }
}
