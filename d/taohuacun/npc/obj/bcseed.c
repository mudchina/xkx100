
inherit ITEM;

void create()
{
	set_name("°×²ËÃç",({"baicai seed"}));
	set_weight(50);
	set("value", 100);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "Ò»´ü°×²ËÃç¡£\n");
                set("unit", "´ü");
        }
}

