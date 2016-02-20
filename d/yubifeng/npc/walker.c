#include <ansi.h>
inherit NPC;

int do_walk();

void create()
{
	set_name("路人", ({ "lu ren", "man", "ren" }) );
        set("gender", "男性");
        set("age", 53 + random(20));
        set("long","这是一个拾荒者，看上去老实巴交的。不过听说他和官府有交情，最好别去招惹。\n");
        set("attitude", "heroism");
        set("str", 35);
        set("int", 15);
        set("con", 19);
        set("dex", 17);

        setup();
        carry_object(CLOTH_DIR"cloth")->wear();
}
