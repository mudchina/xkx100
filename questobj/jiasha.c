// jiasha.c

inherit ITEM;
void setup()
{}

void init()
{
}

void create()
{
	set_name("袈裟", ({"jia sha", "jia", "sha"}));
	set_weight(800);
	set("taskobj", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一件旧得已经看不出颜色的袈裟，上面有好多窟窿。\n");
		set("unit", "件");
		set("material", "cloth");
	}
	setup();
}

