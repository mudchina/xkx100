
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY "爆炒鳝片" NOR, ({"shanpian"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盘香脆的爆炒鳝片。\n");
                set("unit", "盘");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 20);
                set("cook_msg", "
$N将鳝鱼平放在砧板上，用竹签沿肚皮划开二片，去背骨，
去皮，去尾， 用洁净布揩干，不要用水洗，以免影响鲜味，
然后切成荷叶片。再开旺火热猪油锅，将鳝鱼片放下去脆，
倒出，滤去油。在锅内另加少许猪油烧热，将大蒜头拍碎，
倒入锅内炒香，加清汤、菱粉、盐、勾好芡，再将鲜片倒
入略炒，浇上麻油，撒上胡椒粉。\n\n"
		);                
        }
}
