// Room: /d/lingxiao/muwu.c
// Last Modified by Winder on Jul. 15 2001

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "木屋");
	set("long", @LONG
这是凌霄城弟子在城外巡逻护山的哨所，每天都有雪山弟子守卫，
以保护凌霄城安全清净。不过，凭凌霄城在武林中的名头，一般宵小之
辈也不敢来此捣乱。
LONG );
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_sleep_room", "1");
	set("objects", ([
		__DIR__"npc/wang" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"sroad6",
	]));
	create_door("west", "木门", "east", DOOR_CLOSED);
	set("no_clean_up", 0);
	set("coor/x", -30990);
	set("coor/y", -8950);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
} 

