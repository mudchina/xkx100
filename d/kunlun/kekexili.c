// Room: /d/kunlun/kekexili.c
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "可可西里山");
	set("long",@long
可可西里山又称可可稀立山，蒙古语为“青山”的意思。西起木孜
塔格峰，东接巴颜喀拉山，山势平缓，冻土广布，高处少永久性积雪与
冰川。除北侧有淡水湖钦马湖外，其余南北星罗棋布的湖泊均为咸水湖。
草木稀疏，人烟极少。
long);
	set("exits",([
		"east"      : __DIR__"bayankala",
		"northwest" : __DIR__"shankou",
		"north"     : __DIR__"xuedi",
	]));
	set("objects",([
//		"/d/mingjiao/npc/yinli" : 1,
	]));
	set("outdoors", "kunlun");
	set("coor/x", -100000);
	set("coor/y", 20000);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);    
}
