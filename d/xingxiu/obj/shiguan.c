// Room: /d/xingxiu/shiguan.c
// Last Modified by Winder on Apr. 25 2001

#include <ansi.h>
inherit ITEM;

int start_liandu(object me);
int halt_liandu(object me);
void create()
{
	set_name(HIM"石棺"NOR, ({ "shi guan", "coffin", "shi", "guan"}) );
	set_weight(30000000);
	set_max_encumbrance(200000);
	if( clonep() )
		set_default_object(__FILE__);
	else{
		set("no_carry",1);
		set("no_get_from",1);
		set("no_put",1);
		set("unit", "张");
		set("long", "这是一张用整块巨石凿空而制成的石棺，上面残留了一些"RED"血迹"NOR"，
散发出的一股腐烂气味，弥漫了整个山洞。\n");
		set("material","stone");
		set("no_get",1);
		set_temp("poison_type", "阴");
	}
	setup();
}

void init()
{
	add_action("do_liandu", "liandu");
}

void over_liandu(object ob)
{
	object corp;
	remove_call_out("over_liandu");
	ob->delete_temp("liandu");
	if(objectp(corp = present("corpse", ob)))
	{
		if(ob->query_temp("liandued"))
			message_vision("\n$N"RED"里腐烂的尸体犹如一只泄了气的皮球一样，慢慢开始萎缩，最后只剩下一小片血迹在棺底！\n"NOR, ob);
		else message_vision("\n$N"RED"里腐烂的尸体“膨”的一下爆裂开来，溅得到处都是血迹！\n"NOR, ob);
		destruct(corp);
		ob->delete_temp("liandued");
	}
}

int do_liandu()
{
	int liandu_cost, neili_lost, times;
	object ob, me, corp;

	ob = this_object();
	me = this_player();

	if(!ob->query_temp("liandu")) return 0;
	if(ob->query_temp("liandu_target") != me->query("id"))
		return notify_fail("你的手掌刚刚伸出，却被一股无形的大力给震了回来。\n");
	if(!objectp(corp = present("corpse", ob)))
		return notify_fail("你要拿什么炼毒？\n");
	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");
	if( me->is_fighting() )
		return notify_fail("战斗中炼毒？只怕你还没那造诣吧？\n");
	if(me->query_condition("xx_liandu"))
		return notify_fail("你刚刚炼毒完成不久，频繁炼毒会有生命危险的！\n");
	if( (int)me->query("neili") < me->query("max_neili")/2 )
		return notify_fail("你现在的内力不足，强制炼毒会很危险的。\n");
	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("你现在精不够，这样下去会很危险的！\n");
	
	if (me->query_skill_mapped("force") != "huagong-dafa" ||
	me->query_skill_mapped("strike") != "chousui-zhang")
		return notify_fail("你没有使用星宿武功，无法炼毒。\n");										 
	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("你的内力太弱，强制炼毒会很危险的！\n");
	if( objectp( me->query_temp("weapon")) )
		return notify_fail("炼毒时需要双手的配合，所以你最好还是不要拿武器。\n");

	write(BLU"你开始凝神运气，将化功大法功力满布全身。\n"NOR);
	tell_room(environment(me), BLU+me->name()+"脸色忽然变为紫青，双目闪烁出阴阴的蓝光。\n"NOR, ({ me }));
	
	neili_lost = (int)me->query_skill("force")/10 + me->query_skill("poison")/4;
	times = (int)me->query("neili")/(int)neili_lost;
	me->set_temp("pending/liandu", 1);
	me->set_temp("liandu_times", times);
	me->set_temp("liandu/period", 1);
	ob->set_temp("liandu", 1);
	call_out("over_liandu", me->query("neili")/10, ob);
	me->start_busy((: start_liandu :), (:halt_liandu:));
	return 1;
}

int start_liandu(object me)
{
	string force;
	int neili_lost = (int)me->query_skill("force")/10 + me->query_skill("poison")/4;
	int times = (int)me->query_temp("liandu_times");
	int period = (int)me->query_temp("liandu/period");
	
	me->add("neili", -neili_lost);
	me->receive_damage("qi", 5+random(10));
	me->improve_skill("poison", 1);
	switch(period) {
	case 1:
		write("你将内力聚于三焦，舌根微微上抬，双掌平伸按在腐烂的尸体上。\n");
		tell_room(environment(me), "只见"+me->name()+"轻吸了口气，双掌平伸，按在石棺内腐烂的尸体上。\n",({ me }));
		break;
	case 3:
		write("你急催化功大法，将体内的毒素和功力顺手臂直传到腐烂的尸体上。\n");
		break;
	case 5:
		write(HIY"腐尸内的毒素开始缓缓聚于一点，并顺着你的手掌向你侵来。\n"NOR);
		break;
	case 11:
		write(YEL"你全身放松，将内息自丹田循任脉引向会阴穴，引导那毒素向气海而去。\n"NOR);
		tell_room(environment(me), YEL+me->name()+"双掌成爪，一股股青气从指尖透出，直插在腐尸的膻中穴上，好象在吸取什么。\n"NOR,({ me }));
		me->improve_skill("force", me->query_con());
		break;
	case 21:
		write(HIY"\n你双掌游动，指尖扣住腐尸的肺手太阴之脉。功力起於中焦，下络大肠，还循胃口，横出腋下，
行少阴心主之前，循臂内上骨下廉，入寸口，上鱼，左指劲力循鱼际，出大指之端，右指劲力直
出次指内廉，出其端，复汇于中焦。\n"NOR);
		tell_room(environment(me), CYN+me->name()+"双手游动，又扣住了腐尸的肺手太阴之脉。\n"NOR,({ me }));
		break;
	case 31:
		write(HIY"\n腐尸内的毒素越聚越密。你双爪晃过，内力注入其手阳明之脉，起於大指次指之端，循指上廉，
出合谷两骨之间，上入两筋之中，循臂上廉，上肩，上出於柱骨之会上，下入缺盆络肺；其支者，
从上颈贯颊，入下齿中，还出挟口，交人中，左之右，右之左，上挟鼻孔，将内息会引，流向气
海。\n"NOR);
		tell_room(environment(me), CYN+me->name()+"吐气吹向腐尸，只见其片片肌肤随风滑落，胫骨却包裹着一层淡淡的青气！\n"NOR,({ me }));
		break;
	case 41:
		write(HIY"\n你再将双掌按在腐尸三焦手少阳之脉处，一吐一引，过其阳池，外关，上出两指之间，出臂外两骨
之间，上肩而交出足少阳之後，入缺盆，布膻中，散络心胞；又从膻中上出缺盆，上项，直上出耳
上角，以屈下颊至；又从耳後入耳中，出走耳前，交颊。三路合于一处！\n"NOR);
		tell_room(environment(me), CYN+me->name()+"双掌如画太极般划动，只见腐尸上所呈现的青色开始慢慢聚合于其胸口，其色甚阴！\n"NOR,({ me }));
		me->improve_skill("force", me->query_dex());
		break;
	case 51:
		write(YEL"你双掌平抬，凌空运气，开始汇聚腐尸于奇经八脉之毒气！\n"NOR);
		tell_room(environment(me), HIY+me->name()+"双掌平抬，凌空运气，一条条青线围绕著石棺飘动着，倍显阴森！\n"NOR,({ me }));
		break;
	case 61:
		write(BLU"入任脉，起於中极之下，以上毛际，循腹里，上关元，至咽喉，上颐循面，入目络舌！\n"NOR);		
		break;
	case 71:
		write(BLU"入阳脉者，起于跟中，循外踝，上行入风池！\n"NOR);		
		break;
	case 81:
		write(BLU"入阴脉，起於跟中，循内踝，上行至咽喉，交贯冲脉！\n"NOR);		
		break;
	case 91:
		write(BLU"入阳维脉，起於外踝下的金门穴处，循行於下肢，上行到额部阳白穴处！\n"NOR);		
		break;
	case 121:
		write(BLU"入阴维脉，起於内踝上的筑宾穴，上行到颔下的廉泉穴处！\n"NOR);		
		break;
	case 141:
		write(BLU"入冲脉者，起于气冲，并足阳明之经，夹脐上行，至胸中而散也！\n"NOR);		
		break;
	case 161:
		write(BLU"入带脉者，起於季胁，回身一周！\n"NOR); 
		me->improve_skill("force", me->query_con());
		me->add("max_neili", 1);
		break;
	case 201:
		write(RED"豁然间，你感觉到那具尸体就象消失了重量一样，在你内力的催动下缓缓飘浮了起来！\n"NOR);
		tell_room(environment(me), RED"突然，那具尸体就象消失了重量一样，在"+me->name()+"内力的催动下缓缓飘浮了起来！\n"NOR,({ me }));
		break;
	}

	if((int)me->query("neili") < 0 || (int)me->query("jingli") < 0)
	{
		write(GRN"突然间，你感觉到自己丹田中已经空空如也，大惊之下竟被阴寒的毒素顺势而上直抵肺腑！\n"NOR);
		tell_room(environment(me), GRN"突然间，你看见"+me->name()+"全身发颤，一股青气竟然从石棺里自下而上直冲到"+me->name()+"的前胸！\n"NOR,({ me }));
		me->set("neili", 0);
		me->apply_condition("xx_liandu", 10 + random(50));
		over_liandu(this_object());
		me->unconcious();
		return 0;
	}

	if(period==times)
	{
		write(HIW"\n猛地，你感觉到一股至阴的毒气顺手臂袭来，竟然透过你的内劲直抵丹田！\n"NOR);
		write(HIW"这一瞬间，你发觉那至阴的毒气和自己体内原本的毒气相互融合，一同归纳进了气海！\n"NOR);
		tell_room(environment(me),HIY+me->name()+"缓缓收回双掌，笼罩着全身的青气也随之消散了。\n"NOR, ({ me }));
		if(me->query_skill("poison", 1) < 180)
			me->improve_skill("poison", times*neili_lost/2*this_object()->query_temp("liandu"));
		if(me->query_skill("huagong-dafa", 1) < 200)
			me->improve_skill("huagong-dafa", me->query_con()*3);
		me->apply_condition("xx_liandu", 200 + random(200));
		this_object()->set_temp("liandued", 1);
		over_liandu(this_object());
		return 0;
	}
	period++;
	me->set_temp("liandu/period", period);
	return 1;	
}

int halt_liandu(object me)
{
	me->start_busy(1 + random(4));
	if(!wizardp(me))
		me->apply_condition("xx_liandu", 10 + random(50));
	if(living(me))
		message_vision("\n$N轻喝一声，吐气纳精，把双掌从石棺上急急收回。\n", me);	
	over_liandu(this_object());
	return 1;
}

