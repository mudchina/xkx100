#include <ansi.h>
inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name(HIW "七星丸" NOR, ({"qixingwan"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一碗鲜汤。汤清如镜，鱼丸漂浮在汤的面上，洁白如星斗，因此称为“七星丸”。\n");
		set("unit", "碗");
		set("value", 120);
		set("max_liquid", 20);
		set("cook_msg", "
$N将鱼肉用刀背剁成泥，剁好后加清水用力搅匀，再加盐继续搅至鱼肉泡涨起。
$N将猪腿肉去皮去筋，同虾仁混合一起，剁成细末，加盐 少许拌和。然后用
左手将鱼肉泥从拇指与食指之间捏挤出一只只的小丸子，右手随 即用极少的
猪肉虾仁末塞入鱼丸里。这样一只只边裹边放入清水锅内烧熟。然后另用净干锅，
倒入清鸡汤，再从清水锅中将鱼丸捞出，放 入清汤锅内烧开后连汤带鱼丸舀入
汤碗，撒上芹菜末，胡椒粉，浇上麻油。\n\n"
		);		
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"name": "七星丸汤",
		"remaining": 20,
		"drunk_apply": 6,
	]));
}

