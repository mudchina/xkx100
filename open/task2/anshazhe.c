// anshazhe.c 暗杀者
inherit NPC;
#include "aninit.h"

void create()
{
	string weapon;
	int i;

	i = random(sizeof(name_msg));
	set_name(name_msg[i], ({ long_id[i], short_id[i] }) );
	set("gender", random(2)>0 ? "女性" : "男性" );
	set("age", 15 + random(40) );
	set("long","一个普通的人，放在人群中没有一点突出之处。\n");

	weapon = weapon_msg[random(sizeof(weapon_msg))];
	setup();
	carry_object(weapon);
	carry_object("/clone/misc/cloth")->wear();
}

