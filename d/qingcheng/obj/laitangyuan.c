// laitangyuan.c

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("ÀµÌÀÔ²", ({ "lai tangyuan", "tangyuan" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "ÕâÊÇÒ»ÍëÏãÅçÅç¡¢ÌğË¿Ë¿µÄÀµÌÀÔ²¡£\n");
                set("unit", "Íë");
                set("value", 0);
                set("food_remaining", 5);
                set("food_supply", 30);
        }
}
