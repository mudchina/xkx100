#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "紫竹林入口");
	set("long", @LONG
这里是悬崖边上的一小块空地，边上有一片茂密的竹林，
里面黑乎乎的，也不知道通往哪里。
LONG);
	       
        set("no_fight", 1);
        set("no_quit",1);
        set("no_sleep_room",1);
	setup();
}
