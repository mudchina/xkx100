// Room: /d/chengdu/chunxilu1.c
// Last Modifyed by Winder on Jan. 4 2002

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short",HIY "春熙路" NOR);
	set("long", 
"这里便是成都府著名的商业中心，街上行人来来往往，两旁店铺林\n"
"立，热闹非凡，东面有个大酒楼，金色的锦旗迎风飘扬，只见上书四个\n"
"大字格外醒目"+BLINK HIR"“银杏酒楼”"NOR"。西面看起来是个茶馆，一个个衣着光鲜的\n人从那里进进出出。\n"
      );

	set("outdoors", "chengdu");
	set("no_clean_up", 0);
	set("exits", ([
		"south" : __DIR__"chunxilu2",
		"north" : __DIR__"chunxilu",
		"east"  : __DIR__"jiulou1",
		"west"  : __DIR__"chaguan",
	]));
	set("coor/x", -8040);
	set("coor/y", -3020);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);       
}


