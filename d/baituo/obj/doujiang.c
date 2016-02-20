// DOUJIANG.C ¶¹½¬

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("¶¹½¬",({ "jiang"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "Ò»±­ÈÈÆøÌÚÌÚµÄ¶¹½¬¡«¡«¡«\n");
		set("unit", "±­");
		set("value", 500);
        set("max_liquid", 4);
	}
	set("liquid", ([
		"type": "water",
		"name": "¶¹½¬",
		"remaining": 10,
		"drunk_supply": 10,
	]));
	setup();
}

