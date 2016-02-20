#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIG "好逑汤" NOR, ({"haoqiutang"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗碧绿的清汤中浮着数十颗殷红的樱桃，又飘着七八片粉红色的花瓣，
底下衬着嫩笋丁子，红白绿三色辉映，鲜艳夺目。\n");
		set("unit", "碗");
		set("value", 120);
		set("max_liquid", 20);
		set("cook_msg", "
$N取出十余枚樱桃，去核，以斑鸠肉嵌之，将其与桃花瓣、笋尖投入事
先用荷叶熬成的清汤中，用微火焖上片刻。\n\n");		
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"name": "好逑汤",
		"remaining": 20,
		"drunk_apply": 6,
	]));
}

