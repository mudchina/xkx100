// Room: /binghuo/northboat4.c
// Date: Oct.28 1999 by Winder
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "破帆船");
	set("long", @LONG
帆船在海流中无助地漂流着，没有帆，也没有桨。你无奈地看着
它越漂越北。船上水米皆尽，船体破碎支离，惨不忍睹，没一块完整
的地方了。
LONG );
	set("no_sleep_room",1);
	set("outdoors", "binghuo");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

