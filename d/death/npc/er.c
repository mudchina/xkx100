// er.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL "判官" NOR, ({ "pan guan","guan" }) );
	set("long", @LONG
地狱阴司中执掌管带众鬼，以施奖惩之官，手中拿着记载人寿命的生死簿。
LONG);
	set("gender","男性");
	set("str",1000);
	set("title",RED "罚恶司" NOR);			
	set("attitude", "peaceful");
	set("age", 1000);
	set("combat_exp", 100000000);
	set("max_jing", 10000);
	set("max_qi", 10000);
	set("max_neili",10000);
	set("neili",10000);
	setup();
	carry_object( __DIR__"obj/shsbu" )->wear();
}
