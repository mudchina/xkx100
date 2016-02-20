// Feb. 6, 1999 by Winder
inherit ITEM;
void create()
{
        set_name( "情书", ({ "qing shu"}));
        set_weight(300);
        if( clonep() )
            set_default_object(__FILE__);
        else {
            set("unit", "封");
            set("long","这是阿土送给阿凤的情书，你可不要私自打开来看哦。\n");
             }
}
