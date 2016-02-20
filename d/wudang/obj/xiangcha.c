// xiangcha.c Ïã²è

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("Ïã²è",({"tea", "cha", "xiang cha"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»±­ÈÈ²è£¬ÓÆÓÆµØÃ°×ÅÏãÆø¡«¡«¡«\n");
		set("unit", "±­");
		set("value", 1000);
		set("max_liquid", 20);
	}
	set("liquid", ([
		"type": "tea",
		"name": "²è",
		"remaining": 2,
		"drunk_apply": 25,
	]));
}
