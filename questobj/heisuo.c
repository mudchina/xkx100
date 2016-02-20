// heisuo.c  ºÚË÷º

#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create()
{
	set_name(BLK"ºÚË÷"NOR, ({ "heisuo", "bian" }));
	set_weight(500);
	set("taskobj", 1);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "¸ù");
		set("long", "ÕâÊÇÒ»¸ù³¤Ë÷£¬Í¨Ìå÷îºÚÎŞ¹â£¬Îè¶¯Ö®Ê±ÇÆ²»¼û°ëµãÓ°×Ó¡£\n");
		set("value", 0);
		set("material", "leather");
		set("wield_msg", "$N¡¸à§¡¹µÄÒ»Éù¶¶³öÒ»Ìõ$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n¾í»ØÑü¼ä¡£\n");
	}
	setup();
}
