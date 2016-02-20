// Room: /d/mingjiao/mjtianmen.c
// Jan.5 1997 By Venus

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "黄土地");
	set("long", @LONG
这是一片黄土地，尘沙泛起，剑芒凌空，刀枪晃日，杀气盈野，几
个小伙子膀大腰圆，一身短打，练功不辍。到此地，便能感觉到明教百
年兴旺的根柢非虚。
LONG );
	set("exits", ([
		"northwest" : __DIR__"mjtianmen1",
		"southeast" : __DIR__"mjsimen1",
	]));
	set("objects", ([
		"/d/shaolin/npc/mu-ren": 5,
	]));
	set("outdoors", "mingjiao");
	set("coor/x", -51100);
	set("coor/y", 700);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}