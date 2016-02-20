// meng.c

inherit ITEM;
void create()
{
	set_name("梦笔生花", ({ "stone" }) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "一根独特的石柱，下部直如笔杆，上端酷似笔
尖，笔杆和笔尖之间夹一石缝，更显得象一只自然毛笔。\n");
		set("value", 1);
		set("skill", ([
			"name"         : "literate",
			"exp_required" : 0,
			"sen_cost"     : 30,
			"difficulty"   : 15,
			"max_skill"    : 59
		]) );
	}
}
int is_container() { return 1; }
