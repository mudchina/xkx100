// quanzhen-ling.c 全真令

inherit ITEM;

void create()
{
        set_name("全真令", ({"quanzhen ling", "letter", "ling"}));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
                set("long","这是一面银光闪闪的令牌，由丹阳真人签发，凭此可弟子自由向师尊挑战。\n");
//		set("no_drop", "这样东西不能离开你。\n");
                set("material", "steel");
        }
}

