// Room: /d/xingxiu/obj/yushi.c
// Last Modified by Winder on Apr. 25 2001
#include <ansi.h>
inherit ITEM;
void create()
{
	switch(random(8))
	{
		case 0 : set_name(HIW "白云石" NOR, ({ "yushi"})); break;
		case 1 : set_name(GRN "猫眼石" NOR, ({ "yushi"})); break;
		case 2 : set_name(RED "鸡血石" NOR, ({ "yushi"})); break;
		case 3 : set_name(BLU "蓝玉石" NOR, ({ "yushi"})); break;
		case 4 : set_name(WHT "白玉石" NOR, ({ "yushi"})); break;
		case 5 : set_name(MAG "紫花玉" NOR, ({ "yushi"})); break;
		case 6 : set_name(YEL "黄斑玉" NOR, ({ "yushi"})); break;
		case 7 : set_name(CYN "青兰玉" NOR, ({ "yushi"})); break;
	}
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("value", 300000);
		set("unit", "块");
		set("weight", 100);
		set("long", "这是一小块玉石，好象还能值几个钱。\n");
		set("material", "stone");
		}
	setup();
}
