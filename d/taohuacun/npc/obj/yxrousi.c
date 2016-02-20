
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY "鱼香肉丝" NOR, ({"yxrousi"}));
        set_weight(200);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盘鱼香横溢，微带辣味的鱼香肉丝。\n");
                set("unit", "盘");
                set("value", 50);
                set("food_remaining", 4);
                set("food_supply", 20);
                set("cook_msg", "
$N将猪肉、玉兰片、木耳均切丝，入碗中加调料稍腌。再将调料加肉汤
烧开调成芡汁。然后将肉丝下油锅中滑炒散，加姜、蒜、泡红椒炒出
鱼香味，再下入玉兰片、木耳丝煸炒，烹入芡汁。\n\n"
		);               
        }
}
