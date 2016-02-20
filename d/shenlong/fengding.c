// /d/shenlong/fengding 峰顶
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "峰顶");
	set("long", @LONG
这是神龙岛的最高峰，但是却很是宽敞。站在峰顶，极目远眺，但
见四周均是蔚蓝的天空、茫茫的大海。你突然觉得自己是多么的渺小，
犹如沧海之一粟。旁边一群神龙教众在巡逻着，偶尔不怀好意地朝你瞧
几眼。西面是长廊，南面是下山的山道，往北有一条通向后山的小路，
路很小，似乎走的人不多。
LONG
	);
	set("exits", ([
		"east"      : __DIR__"changlang",
		"northdown" : __DIR__"lin1",
		"southdown" : __DIR__"shandao",
	]));
	set("outdoors", "shenlong");
	set("objects", ([
		CLASS_D("shenlong")+"/hesheng" : 1,
	]));

	setup();
	replace_program(ROOM);
}

