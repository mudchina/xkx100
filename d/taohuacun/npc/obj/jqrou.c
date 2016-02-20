
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY "金钱肉" NOR, ({"jqrou"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一盘色香俱佳的金钱肉。\n");
                set("unit", "盘");
                set("value", 50);
                set("food_remaining", 5);
                set("food_supply", 20);
                set("cook_msg", "
$N将猪腿肉片成薄片，每两片留一边不断；再将猪肥膘切成一两块
像银元大小的圆块子，一起放入用酱油、糖、五香粉 、酒调成的卤
内滚一滚，再放着腌约二十分钟。然后将 矸 膘一块块地夹入没有片
断的腿肉片中，并用银签将夹好的肉穿成一串。再抹上干菱粉。最后
开热猪油锅，将穿好的肉片放入锅内炸熟，再一片片地从银签上取下
来，整齐地装在盘中。\n\n"
		);                
        }
}
