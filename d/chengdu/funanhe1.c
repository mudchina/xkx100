// Room: /d/chengdu/eastroad2.c
// Last Modifyed by Winder on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "府南河畔");
	set("long", @LONG
你信步来到了府南河畔，这里便是被称为成都母亲河的府南河，两
岸垂柳，随风飘动，绿草如茵，彩蝶纷飞。河水清澈见底，鱼儿游来游
去，河的对岸有群洗衣妇人，一边辛勤地劳作，一边大声地聊天，欢声
笑语在河的这边都可以听见。远处还有个老渔翁独自垂钓。看到这里，
你也仿佛入画了。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"southeast" : __DIR__"funanhe2",
		"northwest" : __DIR__"chunxilu3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -8050);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}

