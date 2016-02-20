// kudingcha.c

inherit ITEM;
inherit F_LIQUID;

void create()
{
	set_name("茶水碗", ({ "wan", "bowl" }) );
	set_weight(400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "这是一碗苦丁茶。青城出的苦丁茶入口微苦，回味则甜，且甜味绵长，实为上品。\n");
		set("unit", "个");
		set("value", 0);
		set("max_liquid", 60);
	}

	// The liquid contained in the container is independent, we set a copy
	// in each cloned copy.
	set("liquid", ([
		"type": "water",
		"name": "苦丁茶",
		"remaining": 50,
	]) );
}
