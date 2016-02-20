// xishanxinglvtu.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIG"溪山行旅图"NOR,({"painting","xi shan xing lv tu","tu"}) );
	set("taskobj", 1);
	set("long","这是据说已经失传了的范宽真迹，对于爱画之人，算是无价之宝了。\n");
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "幅");
		set("value", 0);
		set_weight(20);
	}
	setup();
}

