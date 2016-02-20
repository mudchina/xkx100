// Feb. 6, 1999 by Winder
inherit ITEM;
void create()
{
        set_name( "扫把", ({ "saoba"}));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","这是一把用来的打扫卫生的扫把。\n");
             }
}
