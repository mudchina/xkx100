// ding.c 神木王鼎

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(YEL"神木王鼎"NOR, ({ "shenmu wangding", "ding" }));
	set_weight(500);
	set("count", 200);
	set_max_encumbrance(1000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "座");
		set("long", 
YEL"这是一座色作深黄的小小木鼎。木鼎雕琢甚是精细，木质坚润似
似玉，木理之中隐隐约约的泛出"RED"红丝"YEL"。鼎侧有五个铜钱大的圆孔，
木鼎齐颈处有一道细缝，似乎分为两截。\n    看来是练功用的(use)。\n"NOR);
		set("value", 2000);
	}
}

int is_container() { return 1; }

void init()
{
	add_action("do_use","use");
}

int do_use(string arg)
{
	object env, target, ob = this_object(), me = this_player();
	string targetname, bugname, bugunit;
	mapping fam;
	int hgdf_sk, poison_sk, skpoint;
	
	if (!present(ob,me)) return 0;

	if( !arg || sscanf(arg, "%s with %s", arg, targetname)!=2 )
		return notify_fail("用法是 use ding with 帮你练功的人\n");

	if ( !id(arg) )
		return notify_fail("你要用什么？");

//	if( query("count") < 1)
//		return notify_fail("这个木鼎看来破烂不堪，恐怕不能用了。\n");

	env = environment(me);
	hgdf_sk = me->query_skill("huagong-dafa", 1);
	poison_sk = me->query_skill("poison", 1);

	if( env->query("no_fight") )
		return notify_fail("这里不适合你用神木王鼎练功。\n");

	if( !objectp(target = present(targetname, env)) )
		return notify_fail("你附近没有这个人。\n");

	if( target == me)
		return notify_fail("自己给自己做药罐？太不值了吧。\n");

	if( target->query("race") != "人类" ) 
		return notify_fail("帮你练功的必须是人。\n");

	if( living(target) && !target->query_temp("noliving") ) 
		return notify_fail("你只能找个不省人事的人做你的练功药罐。\n");

	if (!(fam = me->query("family")) || fam["family_name"] != "星宿派")
		return notify_fail("你试图想看看这木鼎有啥用，可是看不懂！\n");

	if( hgdf_sk < 20)
		return notify_fail("你化功大法火候不够，不能使用神木王鼎！\n");

	if( poison_sk < 20)
		return notify_fail("你的基本毒技太低，没法抵挡木鼎的毒力！\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用神木王鼎！\n");

	if( me->is_fighting() )
		return notify_fail("战斗中无法才能使用神木王鼎！\n");

	if( me->is_busy() )
		return notify_fail("你正忙着呢！哪有空做这水磨功夫？\n");

//	add("count", -1);
	skpoint = poison_sk + random(hgdf_sk);

	switch( random(5))
	{
		case 0:
			bugunit = HIR"一条红艳艳的";
			bugname = HIR"大蜈蚣"HIG;
			break;
		case 1:
			bugunit = HIC"一只青灰色的";
			bugname = HIC"大蜘蛛"HIG;
			break;
		case 2:
			bugunit = BLK"一只花斑黑格";
			bugname = BLK"大蝎子"HIG;
			break;
		default:
			bugunit = HIW"一条白身黑章";
			bugname = HIW"大蟒蛇"HIG;
	}

	message_vision(HIG"
$N取了一只深黄色的小木鼎出来，放在地下，又从鼎底取出一个小小
布包，打了开来，里面是几块黄色、黑色、紫色的香料。$N从每一块
香上捏了少许，放入鼎中，用火刀、火石打着了火，烧了起来，然后合
上鼎盖。

过了一阵，忽听得草丛中瑟瑟声响，绿草中"+bugunit+bugname+"径直爬
向木鼎，从鼎下的孔中钻了进去，便不再出来。

$N把$n的手伸进木鼎，"+bugname+"一伸嘴，就一口咬住了$n的中指。
过了好一会，但见$n的中指上隐隐罩上了一层深紫之色。紫色由浅而
深，慢慢转成深黑，再过一会，黑色自指而掌，更自掌沿手臂上升。

过得片刻，木鼎的孔中有一滴滴黑血滴了下来。$N脸现喜色，忙伸掌
将血液接住，盘膝运功，将血液都吸入掌内。过了好一会，木鼎再无黑
色滴下，$N双掌一搓，瞧自己手掌时，但见两只手掌如白玉无瑕，更
无半点血污。\n"NOR, me, target);

	target->receive_wound("qi", 40); 
	if (hgdf_sk > 20 && hgdf_sk < 150)
	{
		if( SKILL_D("huagong-dafa")->valid_learn(me) )
		{
			me->improve_skill("huagong-dafa", random(skpoint));
			tell_object(me, HIC"你的「化功大法」进步了。\n"NOR);
		}
	}
	if (poison_sk > 20 && poison_sk < 100)
	{
		if( SKILL_D("poison")->valid_learn(me) )
		{
			me->improve_skill("poison", random(skpoint));
			tell_object(me, HIC"你的「基本毒技」进步了。\n"NOR);
		}
	}
	me->start_busy(3);
	return 1;
}

