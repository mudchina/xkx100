// /d/shenlong/huofang 伙房
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "伙房");
	set("long", @LONG
这里是神龙教的伙房，房子的一边是个灶炉，旁边有一个老头在往
灶内添柴，锅内不知煮着是什么东西，不过香味已经让你馋得按捺不住
了。
LONG
	);
	set("exits", ([
		"south" : __DIR__"shibanlu",
	]));
	set("objects",([
		__DIR__"obj/hongcha" : 3,
		__DIR__"obj/shegeng" : 2,
	]));
	setup();
	replace_program(ROOM);
}
