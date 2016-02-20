// bookming.c

inherit ITEM;

void init()
{
}

void create()
{
	set_name("明史辑略", ({"book ming","book","ming"}));
	set_weight(1500);
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一本厚厚的书。\n");
		set("unit", "本");
		set("material", "paper");
	}
	setup();
}
