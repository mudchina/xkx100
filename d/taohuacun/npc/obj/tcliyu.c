
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED "糖醋鲤鱼" NOR, ({"tcliyu"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盘皮酥肉嫩，甜酸鲜美的糖醋鲤鱼。\n");
                set("unit", "盘");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 20);
                set("cook_msg", "
$N将鱼去鳞，开膛取内脏，挖去两鳃，鱼身两面剞上牡丹花刀，
用 精盐、味精腌渍后，挂一层湿淀粉糊，放入七成热的油中炸熟，
外皮焦酥呈金黄色捞出，摆放在鱼池内，再浇上用葱、姜、蒜、
酱油、醋、白糖、精盐、味精、清汤、淀粉制成的芡汁。\n\n"
		);                
        }
}
