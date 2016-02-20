// jinshechui.c ½ğÉß´¸

#include <weapon.h>
inherit HAMMER;

void create()
{
	set_name("½ğÉß´¸", ({ "jinshe chui", "chui","hammer" }));
	set_weight(5000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "±ú");
		set("long", "ÕâÊÇÒ»±ú½ğ¹âÉÁÉÁµÄ´¸±ú³ÊÉßĞÎµÄ´óÌú´¸£¬ºóÃæ´ø×Å³¤³¤µ
ÄÌúÁ´¡£\n");
		set("value", 3000);
		set("material", "steel");
		set("wield_msg", "$N¡¸»©à¥¡¹µÄÒ»Éù,È¡³öÒ»±ú$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n¹Ò»ØÑü¼ä¡£\n");
	}
	init_hammer(80);
	setup();
}
