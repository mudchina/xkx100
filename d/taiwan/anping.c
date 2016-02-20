// Room: /d/taiwan/anping.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "安平镇");
	set("long", @LONG
明朝末年，荷兰人趁中国虚弱，登陆台湾南部，并在安平地区筑热
兰遮城。从此荷兰人自澎湖移台，与中国互市，并将此处视为与日本贸
易的中途站。汉人渔商此后接踵而至，即在城廓外自建新街市，城堡东
方的「台湾街」是台湾最早的商业街。永历十五年，国姓爷东征，次年
收复此城，改名「安平镇」。
LONG );
	set("exits", ([
		"west"      : __DIR__"luermen",
		"southeast" : __DIR__"zhenbeifang",
	]));
	set("objects", ([
		__DIR__"npc/shangren": 2,
		__DIR__"npc/yufu": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2500);
	set("coor/y", -7030);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

