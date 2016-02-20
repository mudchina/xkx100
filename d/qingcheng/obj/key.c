// key.c

inherit ITEM;

void create()
{
	set_name("库房钥匙", ({"qingcheng key", "yaoshi"}));
	set("long", "这是一把很普通的钥匙。\n");
	set("unit", "把");
	set("weight", 10);
	set("no_drop", 1);
}

