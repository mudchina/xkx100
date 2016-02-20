// po-bu.c
inherit ITEM;

void create()
{
        set_name("破布", ({"po bu", "piece"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long","这是一块破布，凭此可直接向简长老要求升袋。\n");
                set("material", "cloth");
        }
}
