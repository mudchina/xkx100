// mamian.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIY "马面" NOR, ({ "ma mian" }) );
        set("nickname",CYN "妖怪" NOR);
        set("long",GRN @LONG
一个似人非人，似畜非畜的妖怪，人身马面，似笑似哭，尖牙龇露...
LONG NOR);
	set("max_jing", 10000);
	set("max_qi", 10000);
        set("age",1000000);
	set("combat_exp",1000000);
        
	setup();
}
int is_ghost()
{  
      return 1;
}
