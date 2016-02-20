// xishanxinglvtu.c
// Last Modified by winder on Nov. 17 2000

inherit ITEM;

void create()
{
        set_name("溪山行旅图", ({ "painting", "xi shan xing lv tu", "tu" }) );
	set("long","这是据说已经失传了的范宽真迹，对于爱画之人，算是无价之宝了。\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "幅");
                set("no_get", "那是无价之宝，对方连睡觉都揣在怀里的！\n");
                set("no_drop", "这可是无价之宝，你这么老大一个人，居然如此不识货？！\n");
		set("value", 10000);
	        set_weight(20);
//		set("treasure", 1);
        }
        setup();
}

