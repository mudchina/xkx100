//zhenzhu.c
inherit ITEM;
void create()
{
        set_name( "夜明珠", ({ "yeming zhu","zhu"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long","这是一颗夜明珠，悠悠的放着柔和的光，看起来是做装饰的好东西。\n");
                set("value", 10000);
                set("material", "iron");
              }
}
