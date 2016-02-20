// zishi.c
#include <ansi.h>
inherit NPC;
 
void create()
{
        set_name("紫衫侍者", ({ "zishan shizhe","shizhe","zhe" }) );
        set("gender", "男性" );
        set("age",18);
        set("class", "hemuya");
        set("combat_exp", 1000);
        set_skill("unarmed", 50);
        set_skill("dodge", 70);
        set_skill("force",100);
        set("force",300);
        set("max_force",300);
	set("party/party_name", HIB"日月神教"NOR);
	set("party/rank", HIW"教众"NOR);

        setup();
	carry_object(__DIR__"obj/zichoush")->wear();
}
