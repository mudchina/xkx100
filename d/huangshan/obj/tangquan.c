// tangquan.c

inherit ITEM;

void create()
{
	set_name("汤泉", ({ "tang quan", "tang", "quan" }) );
	set_weight(500);
	set_max_encumbrance(8000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
		set("long", "一个已经干涸了的泉孔。\n");
		set("value", 1);
	}
}

int is_container() { return 1; }

