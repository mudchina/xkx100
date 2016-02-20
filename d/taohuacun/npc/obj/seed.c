inherit ITEM;

void create()
{
	set_name("种子",({"seed","zhongzi"}));
	set_weight(50);
	if( clonep() )
                set_default_object(__FILE__);
        else {
//                set("long", "一包" + ob->query("name") + "。\n");
                set("unit", "包");
        }
}

