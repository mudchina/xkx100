// ruzhu.c 片皮乳猪

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
	set_name(HIY "片皮乳猪" NOR, ({"ruzhu"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
//		set("long", "鸡豆花色白细嫩，汤清味鲜，源于豆花，高于豆花，
//被誉名为“豆花不用豆，吃鸡不见鸡”的佳肴美馔。\n");
		set("long","片皮乳猪是广东地方代表菜之一。传统的“烧乳猪”在烧烤过程
中，加入麦芽糖起焦化着色作用，加入白醋起脆皮作用，而最重
要的是加入了白酒起到了酥化的效果，制作成了“麻皮乳猪”。
“麻皮乳猪”有两种上菜方法，一为“片皮”，一为“斩件”，
前者跟甜酱、千层饼、细砂糖和葱球，后者跟甜酱和细砂糖即可。\n");
		set("unit", "只");
		set("value", 300);
		set("food_remaining", 5);
		set("food_supply", 100);
	}
}