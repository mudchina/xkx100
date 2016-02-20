// Room: /d/kunlun/sleeproom.c
// Last Modified by Winder on Nov. 15 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","卧室");
	set("long",@long
这里是何太冲最宠爱的第五小妾五姑的卧房。刚一进房，扑鼻便是
一股药气，里面还能闻到一股十分古怪的气息，过了片刻，更觉得这气
息忽浓忽淡，甚是奇特。床上躺着一个人，这人面向帐里，喘气甚急，
象是扯着风箱。窗子(window)都是紧紧关着。
long);
	set("item_desc", ([
		"window" : "房里很闷，你不禁想打开窗子透透气。\n",
	]));
	set("objects",([
		__DIR__"npc/wugu" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"tieqinju",
	]));
	create_door("west", "小门", "east", DOOR_CLOSED);
	set("coor/x", -119970);
	set("coor/y", 40140);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}