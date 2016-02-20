// jindan.c
#include <weapon.h>
#include <ansi.h>

inherit THROWING;

void create()
{
        set_name(HIY"金胆"NOR, ({ "jin dan", "dan" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "袋");
                set("value", 0);
                set("base_unit", "颗");
                set("base_weight", 300);
                set("base_value", 0);
                set("material", "gold");
                set("long", HIW"黄澄澄的金胆，比之铁胆固重了一倍有余，而且大显华贵之气。\n"NOR);
                set("wield_msg", HIC"$N迅速地从暗器袋中掏出一些金胆，捏在手中就待发出！\n"NOR);
                set("unwield_msg",HIC"$N将手里剩下的金胆尽数放回暗器袋中。\n"NOR);
        }
        set_amount(50);
        init_throwing(25);
        setup();
}
