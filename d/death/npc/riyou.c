// riyou.c

#include <ansi.h>
inherit NPC;
void create()
{
	set_name("日游神", ({ "ri you" }) );
	set("long",HIY @LONG
               阴界之神
LONG NOR);
        set("gender","男性");
        set("str",1000);
        set("title",HIY "阴界之神" NOR);            
	set("attitude", "peaceful");
	set("age", 1000);
	set("combat_exp", 100000000);
	set("max_jing", 10000);
	set("max_qi", 10000);
        set("max_neili",10000);
        set("neili",10000);
	setup();
}
