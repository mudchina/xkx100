#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(RED"西湖醋鱼"NOR, ({"xhcuyu"}));
        set_weight(1300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盘清甜可人的西湖醋鱼，用西湖中的金色鲤鱼
烧制而成，是西湖第一名菜。\n");
                set("unit", "碗");
                set("value", 120);
                set("food_remaining", 20);
                set("food_supply", 20);
                set("cook_msg", "
$N先将饿养两天,已排除泥土味的鲤鱼宰杀后，去掉鳞、鳃和内脏，
洗净，从头至尾片成两片，再坡刀剞上刀纹，放入 沸水中稍煮，用
筷子扎鱼的颌下部，能轻轻扎入时即捞出，鱼背相对装入盘内。用
煮鱼的汤水适量，加入酱油、醋、绍酒、白糖，烧开后，淋入湿淀粉，
推搅成米汤汁，浇在鱼身上。\n\n"
		);                
        }
}
