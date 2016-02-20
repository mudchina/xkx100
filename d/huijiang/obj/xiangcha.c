// Room: /d/huijiang/obj/xiangcha.c Ïã²è
// Last Modified by winder on Sep. 12 2001

inherit ITEM;
void init();

void create()
{
	set_name("Ïã²è",({"tea", "cha", "xiang cha"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»±­ÈÈ²è£¬ÓÆÓÆµØÃ°×ÅÏãÆø¡«¡«¡«\n");
		set("unit", "±­");
		set("value", 30);
		set("remaining",10);
		set("drink_supply", 20);
	}
	set("liquid", ([
		"type": "tea",
		"name": "²è",
		"remaining": 15,
		"drunk_apply": 5,
	]));
}

