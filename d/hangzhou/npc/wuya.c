// wuya.c
// Last Modified by winder on Aug. 1 2002

inherit NPC;

void create()
{
        set_name("ÎÚÑ»", ({ "wuya", "craw" }) );
	set("race", "·ÉÇİ");
        set("age", 3);
        set("long", "Ò»Ö»ºÚÉ«µÄÎÚÑ»£¬³óÂª¼«ÁË¡£\n");
        set("attitude", "peaceful");

        set("combat_exp", 300);
        set_temp("apply/attack", 3);
        set_temp("apply/defense", 5);
        set_temp("apply/armor", 1);

        set("chat_chance", 10);
        set("chat_msg", ({
		"ÎÚÑ»¡¸¸Â¸Â¡¹½ĞÁË¼¸Éù¡£\n",
		"ÎÚÑ»½ĞµÀ£º¡¸¸Â¸Â¡¹¡£\n",
        }) );

        setup();
}
