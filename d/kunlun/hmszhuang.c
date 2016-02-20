// Room: /d/kunlun/hmszhuang.c
// Last Modified by winder on Jun. 29 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIR"红梅庄门"NOR);
	set("long", @LONG
这是一座颇大的庄子。一眼看去就知道此间主人是当地的富豪，在
昆仑山中有这么大的一座山庄确实非常少见。相传，此间主人也是武林
中人，所以路过之人也不敢随意的进入，当以江湖之礼求见。
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"north"    : __DIR__"hmszdating",
		"eastdown" : __DIR__"hmszroad2",
		"westdown" : __DIR__"shanxi",
	]));
	set("objects",([
		__DIR__"npc/yao" : 1,
	]));
	set("outdoors", "hongmei");
	set("coor/x", -90030);
	set("coor/y", 10010);
	set("coor/z", 50);

	setup();
	replace_program(ROOM);
}
