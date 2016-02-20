// tuijianxin-2.c 推荐信 志-处

inherit ITEM;

void create()
{
        set_name("推荐信", ({"quanzhen xin2", "xin2", "letter2"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
                set("long","这是一封志字辈师尊们为你写的推荐信，凭此可直接向处字辈师长们学习武艺。\n");
//		set("no_drop", "这样东西不能离开你。\n");
                set("material", "paper");
        }
}

