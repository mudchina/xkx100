// Room: /d/nanshaolin/shiting6.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short","石亭");
	set("long", @LONG
这里是深藏地下的暗黑色的石亭，想是长年无光透入，一切都显的
暗淡模糊。一盏忽明忽灭的油灯，幽灵般的吐着暗绿色的灯焰，一个面
无表情，无生命的石人，木然的站在这里。
LONG );
	set("exits", ([
		"north" : __DIR__"shiting7",
		"south" : __DIR__"shiting5",
	]));
	set("objects",([
		__DIR__"obj/liaochan" : 1,
	]));
	setup();
}
