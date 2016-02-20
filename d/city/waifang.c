// Room: /yangzhou/waifang.c
// Last Modified by Winder on Jul. 20 2000

#include <room.h>
inherit ROOM;

void create()
{
	set("short","媚香楼");
	set("long",@LONG
外房陈设幽雅，雕梁画栋，绣幕罗帏，地铺五彩绒毡，壁悬八爱名
画，中挂湘竹灯四，系绘《六才》全本。中设楠木天然几，大理石四仙
木桌，古铜瓶中养碧桃一枝。壁厢位置竹叶玛瑙榻床，红木圆台，甚是
精巧。旁有一纱橱，橱门启处，别有洞天。
LONG );
	set("exits",([ /* sizeof() == 1 */
		"east"  : __DIR__"woshi",
		"south" : __DIR__"meixiangyuan",
	]));
	set("objects", ([
		__DIR__"npc/lulixian" : 1,
	]));
	create_door("east", "纱橱门", "west" , DOOR_CLOSED); 
	set("coor/x", 41);
	set("coor/y", 21);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}