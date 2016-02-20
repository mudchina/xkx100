// key2.c

inherit ITEM;

void create()
{
	set_name("铁钥匙", ({"tie key", "key", "yaoshi"}));

	set("long", "这是一把铁钥匙，不知道有什么用。\n");
	set("unit", "把");
	set("weight", 10);
	set("no_drop", 1);
}

