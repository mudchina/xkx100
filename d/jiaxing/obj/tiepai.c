// tiepai.c

inherit ITEM;

void create()
{
        set_name("铁牌", ({ "qulingfeng tiepai", "tiepai", "pai" }) );
	set("long","
一面做成八卦形状的铁牌，翻过来看，背面写着一个“曲”字。
");
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "面");
        }
        setup();
}

