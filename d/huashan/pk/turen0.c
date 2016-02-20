// Room: /d/pk/turen0.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", MAG "紫竹林" NOR);
	set("long", @LONG
这里就是华山舍身崖顶上的紫竹林了，放眼望去，四
周的翠竹拢罩在一层紫雾中，雾霭弥蒙，身处其中，你才
能真正体会＂只在此山中，云深不知处＂的妙境。每年的
华山论剑大会便在此竹林中举行。
LONG
	);
	set("no_quit",1);
	set("bwdhpk",1);
	set("no_sleep_room",1);
	setup();
}
void init()
{
  object me = this_object();
  me->set("exits/east",__DIR__"turen"+random(7));
  me->set("exits/west",__DIR__"turen1"+random(3));
  me->set("exits/northeast",__DIR__"turen"+random(9));
  me->set("exits/northwest",__DIR__"turen"+random(9));
}
