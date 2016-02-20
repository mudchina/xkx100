// human.c
// From ES2
// Modified by Xiang@XKX

// A normal human is at least 40 kg weight
#define BASE_WEIGHT 40000

inherit F_DBASE;
inherit F_SKILL;

mapping *combat_action = ({
	([	"action":		"$N挥拳攻击$n的$l",
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N往$n的$l一抓",
		"damage_type":	"抓伤",
	]),
	([	"action":		"$N往$n的$l狠狠地踢了一脚",
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N提起拳头往$n的$l捶去",
		"damage_type":	"瘀伤",
	]),
	([	"action":		"$N对准$n的$l用力挥出一拳",
		"damage_type":	"瘀伤",
	]),
});

void create()
{
	seteuid(getuid());
	set("unit", "位");
	set("gender", "男性");
	set("can_speak", 1);
	set("attitude", "peaceful");
	set("limbs", ({
		"头部",	"颈部",	"胸口",	"后心",	"左肩",	"右肩",	"左臂",
		"右臂",	"左手",	"右手",	"腰间",	"小腹",	"左腿",	"右腿",
		"左脚",	"右脚"
	}) );
}

void setup_human(object ob)
{
	mapping my;
	int xism_age;

	my = ob->query_entire_dbase();

	ob->set("default_actions", (: call_other, __FILE__, "query_action" :));
	
	if( undefinedp(my["age"]) ) my["age"] = 14;
	if (undefinedp(my["str"])) my["str"] = 10 + random(21);
	if (undefinedp(my["con"])) my["con"] = 10 + random(21);
	if (undefinedp(my["dex"])) my["dex"] = 10 + random(21);
	if (undefinedp(my["int"])) my["int"] = 10 + random(21);
	if (undefinedp(my["per"])) my["per"] = 10 + random(21);
	if (undefinedp(my["kar"])) my["kar"] = 10 + random(21);

	if( userp(ob) || undefinedp(my["max_jing"]) ) {

		if( my["age"] <= 14 ) my["max_jing"] = 100;
		else if( my["age"] <= 30 ) my["max_jing"] = 100 + (my["age"] - 14) * my["int"];
		else if( my["age"] > 60 ) my["max_jing"] -= (my["age"] - 60) * 5;
		else my["max_jing"] = my["int"] * 16 + 100;

		// 道家保精：
		if(my["age"] > 60 && (int)ob->query_skill("taoism", 1) >= 120)
		{
			my["max_jing"] += (my["age"] - 60) * 5;
		}

		// 佛家养精：３０岁前补精，３０岁后长精
		if((xism_age=(int)ob->query_skill("buddhism", 1)) > 39);
		{
			xism_age = xism_age/2;
			if (my["age"] <= 30) xism_age -= my["age"];
			else xism_age -= 30;
			
			if (xism_age > 0) my["max_jing"] += xism_age *((int)ob->query_skill("hunyuan-yiqi", 1)/10); 
		}
		
		if( my["max_jingli"] > 0 ) my["max_jing"] += my["max_jingli"] / 4;
	}
	if( userp(ob) || undefinedp(my["max_qi"]) ) {
		
		if( my["age"] <= 14 ) my["max_qi"] = 100;
		else if( my["age"] <= 30 ) my["max_qi"] = 100 + (my["age"] - 14) * my["con"];
		else if( my["age"] > 60 ) my["max_qi"] -= (my["age"] - 60) * 5;
		else my["max_qi"] = my["con"] * 16 + 100;
		
		// 佛家保气：
		if(my["age"] > 60 && (int)ob->query_skill("buddhism", 1) >= 120)
		{
			my["max_qi"] += (my["age"] - 60) * 5;
		}

		// 道家练气：３０岁前补气，３０岁后长气
		if((xism_age=(int)ob->query_skill("taoism", 1)) > 39);
		{
			xism_age = xism_age/2;
			if (my["age"] <= 30) xism_age -= my["age"];
			else xism_age -= 30;
			
			if (xism_age > 0) my["max_qi"] += xism_age *((int)ob->query_skill("taiji-shengong", 1)/10); 
		}
		
		if( my["max_neili"] > 0 ) my["max_qi"] += my["max_neili"] / 4;
	}

	ob->set_default_object(__FILE__);
	if( !ob->query_weight() ) ob->set_weight(BASE_WEIGHT + (my["str"] - 10)* 2000);
}

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}
