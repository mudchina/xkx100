// yaoshi.c

inherit ITEM;

void create()
{
	set_name("牢房钥匙", ({"key","lfkey"}));
	set("long",
		"这是一把牢房钥匙。\n");
	set("unit", "把");
	set("weight", 10);
	set("value", 100);
        set("no_drop", "这样东西不能离开你。\n");
}

