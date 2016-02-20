// Obj: /d/guiyun/obj/tuijian_xin.c
// Last Modified by winder on Jul. 9 2001

inherit ITEM;

void create()
{
        set_name("推荐信", ({ "recommend letter", "letter", "xin" }) );
	set("owner", "jpei");
	set("long","这是陆乘风写给黄药师的一封信。\n");
        set_weight(2);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "封");
        }
        setup();
}

