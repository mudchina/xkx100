// camel.c

#include <command.h>
#include <dbase.h>
#include <origin.h>

inherit NPC;

void create()
{
        set_name("°×ÂæÍÕ", ({ "camel" }));
        set("long","Ò»Æ¥°×ÂæÍÕ¡£\n");
	set("race", "×ßĞó");
        set("age", 5);
        set("attitude","heroism");
        set("str", 30);
        set("dex", 35);
        set("con", 40);
        set("int", 10);
        set("shen", 1);
        set("combat_exp", 2000);
        setup();
}
