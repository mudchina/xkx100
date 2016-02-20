
inherit ITEM;

void create()
{
	set_name("暗门钥匙", ({"anmenkey"}));
	set("long",
		"这是一把金钥匙。\n");
	set("unit", "把");
	set("weight", 10);
	set("value", 10000);
        set("no_drop", "这样东西不能离开你。\n");
}

