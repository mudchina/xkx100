// Room: /d/nanshaolin/lshuyuan.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIM"龙树院"NOR);
	set("long", @LONG
这是一处偏僻的小院，院中栽着两株高大的槐树，显得极是宁静幽
深。这里是少林武僧们领取武器和防具之地，汇集了天下各派惯用的各
类兵刃。少林武技天下驰名，为防止练功受伤，这里也一并供给各类防
具。院门口站着两名僧兵，手持戒刀，严密的守护着这里。
LONG );
	set("exits", ([
		"east"  : __DIR__ "huaishu5",
		"north" : __DIR__ "wuqiku",
		"south" : __DIR__ "fangjuku",
	]));
	set("outdoors","nanshaolin");
	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));
	set("coor/x", 1790);
	set("coor/y", -6200);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}



