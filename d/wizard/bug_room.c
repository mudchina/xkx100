// /d/wizard/guest_room.c

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", HIC "BUG留言室" NOR);
	set("long", @LONG
这里是巫师处理玩家提出的bug的地方，为便于巫师统一管
理和玩家参看巫师解决后的反馈，这里只能发表(post)有关游
戏bug问题，以供巫师解决。玩家可以在此发表任何符合该主题
的文章，巫师也将尽力解决并回复之。
LONG
);

	set("exits", ([
		"east": __DIR__"guest_room",
]));
	set("no_fight", 1);
	setup();
	"/clone/board/bug_b"->foo();
  replace_program(ROOM);
}