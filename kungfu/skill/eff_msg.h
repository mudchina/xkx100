// eff_msg.h
/*  在相应的perform里加上：
	#include "/kungfu/skill/eff_msg.h";
	int p;
	p = (int)target->query("qi")*100/(int)target->query("max_qi");
	msg += damage_msg(damage, "瘀伤");
	msg += "( $n"+eff_status_msg(p)+" )\n";  
  或者 msg += "( $n"+status_msg(p)+" )\n";
*/
#include <ansi.h>
string eff_status_msg(int ratio)
{
	if (ratio==100) return HIG"看起来气血充盈，并没有受伤。"NOR;
	if (ratio > 95) return HIG"似乎受了点轻伤，不过光从外表看不大出来。"NOR;
	if (ratio > 90) return HIY"看起来可能受了点轻伤。"NOR;
	if (ratio > 80) return HIY"受了几处伤，不过似乎并不碍事。"NOR;
	if (ratio > 60) return HIY"受伤不轻，看起来状况并不太好。"NOR;
	if (ratio > 40) return HIR"气息粗重，动作开始散乱，看来所受的伤着实不轻。" NOR;
	if (ratio > 30) return HIR"已经伤痕累累，正在勉力支撑着不倒下去。"NOR;
	if (ratio > 20) return HIR"受了相当重的伤，只怕会有生命危险。"NOR;
	if (ratio > 10) return RED"伤重之下已经难以支撑，眼看就要倒在地上。"NOR;
	if (ratio > 5 ) return RED "受伤过重，已经奄奄一息，命在旦夕了。"NOR;
	return RED"受伤过重，已经有如风中残烛，随时都可能断气。"NOR;
}

string status_msg(int ratio)
{
	if( ratio==100 ) return HIG"看起来充满活力，一点也不累。"NOR;
	if( ratio > 95 ) return HIG"似乎有些疲惫，但是仍然十分有活力。"NOR;
	if( ratio > 90 ) return HIY"看起来可能有些累了。"NOR;
	if( ratio > 80 ) return HIY"动作似乎开始有点不太灵光，但是仍然有条不紊。"NOR;
	if( ratio > 60 ) return HIY"气喘嘘嘘，看起来状况并不太好。"NOR;
	if( ratio > 40 ) return HIR"似乎十分疲惫，看来需要好好休息了。"NOR;
	if( ratio > 30 ) return HIR"已经一副头重脚轻的模样，正在勉力支撑着不倒下去。"NOR;
	if( ratio > 20 ) return HIR"看起来已经力不从心了。"NOR;
	if( ratio > 10 ) return RED"摇头晃脑、歪歪斜斜地站都站不稳，眼看就要倒在地上。"NOR;
	return RED"已经陷入半昏迷状态，随时都可能摔倒晕去。"NOR;
}

string damage_msg(int damage, string type)
{
	string str;

	if( damage == 0 ) return "结果没有造成任何伤害。\n";

	switch( type ) {   
	case "擦伤":
	case "割伤":
		if( damage < 10 ) return "结果只是轻轻地划破$p的皮肉。\n";
		if( damage < 50 ) return "结果在$p$l划出一道细长的血痕。\n";
		if( damage < 100 ) return "结果「嗤」地一声，在$n身上划出一道伤口！\n";
		if( damage < 170 ) return "结果「嗤」地一声，在$n身上划出一道血淋淋的伤口！\n";
		if( damage < 280 ) return "结果「嗤」地一声，在$n身上划出一道又长又深的伤口，溅得$N满脸鲜血！\n";
		return "结果只听见$n一声惨嚎，$w已在$p$l划出一道深及见骨的可怕伤口！！\n";
		break;
	case "刺伤":
		if( damage < 10 ) return "结果只是轻轻地刺破$n的皮肉。\n";
		if( damage < 50 ) return "结果在$n$l刺出一个创口。\n";
		if( damage < 100 ) return "结果「噗」地一声刺入了$n$l寸许！\n";
		if( damage < 170 ) return "结果「噗」地一声刺进$n的$l，使$p不由自主地退了几步！\n";
		if( damage < 280 ) return "结果「噗嗤」地一声，$w已在$n$l刺出一个血肉模糊的血窟窿！\n";
		return "结果只听见$n一声惨嚎，$w已在$p的$l对穿而出，鲜血溅得满地！！\n";
		break;
	case "砸伤":
		if( damage < 20 ) return "结果只是轻轻地碰撞到了$n一下，没有造成什么伤害。\n";
		if( damage < 60 ) return "结果$w只将$n的$l砸出一块瘀红。\n";
		if( damage < 120 ) return "结果「啪」地一声，$w打中$n的$l，登时肿了一块老高！\n";
		if( damage < 240 ) return "结果$w重重得击中$n的$l，打得$p倒退数步，「哇」地吐出一大口鲜血！\n";
		if( damage < 380 ) return "结果只听见「硼」地一声巨响，$w打在$n身上，将$p像一捆稻草般击飞出去！\n";
		return "只见$w重重地撞击在$n的身上，几声骨碎声中，$p象散了架似的瘫了下去！！\n";
		break;
	case "瘀伤":
		if( damage < 10 ) return "结果只是轻轻地碰到，比拍苍蝇稍微重了点。\n";
		if( damage < 20 ) return "结果在$p的$l造成一处瘀青。\n";
		if( damage < 40 ) return "结果一击命中，$n的$l登时肿了一块老高！\n";
		if( damage < 80 ) return "结果一击命中，$n闷哼了一声显然吃了不小的亏！\n";
		if( damage < 120 ) return "结果「砰」地一声，$n退了两步！\n";
		if( damage < 200 ) return "结果这一下「砰」地一声打得$n连退了好几步，差一点摔倒！\n";
		if( damage < 300 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
		if( damage < 400 ) return "结果只听见「砰」地一声巨响，$n像一捆稻草般飞了出去！！\n";
		return "只听见$n一声惨叫，整个身体象断了线的风筝一样飞了出去！！\n";
		break;
	case "内伤":
		if( damage < 10 ) return "结果只是把$n打得退了半步，毫发无损。\n";
		if( damage < 20 ) return "结果$n痛哼一声，在$p的$l造成一处瘀伤。\n";
		if( damage < 50 ) return "结果一击命中，把$n打得痛得弯下腰去！\n";
		if( damage < 100 ) return "结果$n闷哼了一声，脸上一阵青一阵白，显然受了点内伤！\n";
		if( damage < 200 ) return "结果$n脸色一下变得惨白，昏昏沉沉接连退了好几步！\n";
		if( damage < 300 ) return "结果重重地击中，$n「哇」地一声吐出一口鲜血！\n";
		if( damage < 400 ) return "结果「轰」地一声，$n全身气血倒流，口中鲜血狂喷而出！\n";
		return "结果只听见几声喀喀轻响，$n一声惨叫，像滩软泥般塌了下去！！\n";
		break;   
	case "震伤":		
		if( damage < 100 ) return "结果$n受到$N的内力反震，闷哼一声。\n";
		if( damage < 200 ) return "结果$n被$N以内力反震，「嘿」地一声退了两步。\n";
		if( damage < 300 ) return "结果$n被$N以内力一震，胸口有如受到一记重锤，连退了五六步！\n";
		return "结果$n被$N的内力一震，眼前一黑，身子向后飞出丈许！！\n";
		break;   
	case "抓伤":     
		if( damage < 10 ) return "结果只是在$n$l处轻轻刮过，没有什么伤害。\n";
		if( damage < 25 ) return "结果$n皱了皱眉，$p的$l已经被拉出了一道浅浅的血痕。\n";
		if( damage < 50 ) return "结果拉下来$n$l的一点皮肉，疼得$p「哇哇」怪叫了起来！\n";
		if( damage < 100 ) return "结果「唰」地一声，$n的$l上顿时被抓出五道血痕，鲜血流了出来！\n";
		if( damage < 200 ) return "结果$n疼得大叫一声，$p$l上被抓出了几道深深的血沟，鲜血直流！\n";
		if( damage < 300 ) return "结果只听见$n一声惨嚎，$N的手抓已在$p的$l处刺出了五个血肉模糊的窟窿！\n";
		if( damage < 400 ) return "结果「啊」地一声惨叫，$n身上$p处被$N抓下了一大片皮肉，鲜血横飞满地！！\n";
		return "结果伴随着$n一声凄惨的嚎叫，直透$p$l处，连皮带肉扯下一大块，露出了血淋淋的骨头！！\n";
		break;       
	default:
		if( !type ) type = "伤害";
		str =  "结果造成非常可怕的严重";
		if( damage < 230 ) str = "结果造成极其严重的";
		if( damage < 170 ) str = "结果造成十分严重的";
		if( damage < 120 ) str = "结果造成相当严重的";
		if( damage < 80 ) str = "结果造成颇为严重的";
		if( damage < 50 ) str = "结果造成一处严重";
		if( damage < 30 ) str = "结果造成一处";
		if( damage < 20 ) str = "结果造成轻微的";
		if( damage < 10 ) str =  "结果只是勉强造成一处轻微";
		return str + type + "！\n";
	}
}
