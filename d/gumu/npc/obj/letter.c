// letter.c

inherit ITEM;

void create()
{
        set_name("信", ({"long xin", "xin", "letter"}));
        set_weight(100);
        set("value",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("long","这是一封杨过给小龙女的书信。\n");
//		set("no_drop", "这样东西不能离开你。\n");
                set("material", "paper");
        }
}

