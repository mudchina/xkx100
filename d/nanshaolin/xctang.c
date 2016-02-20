// Room: /d/nanshaolin/xctang.c
// Last Modified by winder on May. 29 2001

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",HIR"心禅堂"NOR);
	set("long", @LONG
一座宽敞的禅室，并非用土木建成，而是依山而建，四壁如仞，都
是石壁。如此山间石室，若非浑然天成，定是有前辈高僧，以禅心智慧，
绝大佛力开山而致了。室内烛火通明，终年不息，正中供奉着我佛的法
像，与大殿不同的是做千手如来收万宝势。职事僧在殿内四处巡视，以
备所需。一位老僧瞑目跌坐，内视参禅。
LONG );
	set("exits", ([
		"west"  : __DIR__"xclang",
		"south" : __DIR__"xcping",
		"north" : __DIR__"duanya",
	]));
        set("objects",([
		CLASS_D("nanshaolin")+"/dabing" : 1,
        ]));
        set("coor/x", 1820);
	set("coor/y", -6090);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
