// huang.c

inherit ITEM;
void create()
{
	set_name("»ÆÙ©", ({ "huang kan","huang", "kan" }) );
	set_weight(500);
	set_max_encumbrance(80000);
	set("no_get", 1);
	set("no_shown", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "×ù");
		set("long", "Ò»×ùÏÉ·çµÀ¹Ç£¬ÊÖ³ÖÁîÅÆ»ÆÙ©ËÜÏñ¡£\n");
		set("value", 1);
	}
}

int is_container() { return 1; }

