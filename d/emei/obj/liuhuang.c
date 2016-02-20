// liuhuang.c Áò»Ç
inherit ITEM;
void create()
{
        set_name("Áò»Ç", ({"liuhuang"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "Ò»¿é»ÆÉ«µÄÁò»Ç¾§Ìå¡£\n");
                set("unit", "¿é");
                set("value", 10);
        }
}
