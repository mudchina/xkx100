// difu2.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW "酆都地府" NOR);
	set("long",BLU @LONG
这里就是阴间鬼魂都必须通过的酆都城，是冥府的中心。往南不远
处就是著名的鬼门关，鬼魂进了鬼门关，就再也不能回头了。四下里影
影幢幢，但是却听不到半点声音，不时有鬼魂从你身边而过，你却摸它
不到，一切都想在梦里一样。东边是一个小店，店门没有关，却无风自
晃，「冈当冈当」地响着。北面有一个大殿，黑漆漆的。
LONG NOR );
	set("no_fight", 1);
	set("exits", ([
		"north" : __DIR__"dadian",
		"south" : __DIR__"difu1",
		"west"  : __DIR__"inn1",
		"east"  : __DIR__"inn2",
	]));
	set("objects", ([
		__DIR__"npc/yeyou": 1,
		__DIR__"npc/riyou": 1,
	]) );

	setup();
	replace_program( ROOM );
}

