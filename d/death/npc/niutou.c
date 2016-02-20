// niutou.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIB "牛头" NOR, ({ "niu tou" }) );
        set("nickname",CYN "妖怪" NOR);
        set("long",RED @LONG
一个似人非人，似畜非畜的妖怪，人身牛头，似笑似哭，尖牙龇露...
LONG NOR);
        set("age",0);
	set("max_jing", 10000);
	set("max_qi", 10000);
	set("combat_exp",1000000);
        
	setup();
}
int is_ghost()
{  
      return 1;
}
