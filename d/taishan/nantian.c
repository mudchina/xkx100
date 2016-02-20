// Room: /d/taishan/nantian.c
// Last Modified by Winder on Aug. 25 2001

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "南天门");
	set("long", @LONG
走完了十八盘，便到南天门。南天门又称“三天门”，门为城楼式
建筑，门边有一副对联(lian)，上覆摩空阁，是泰山顶的入口处。从这
里附视山下，群山如龟伏地，河流如蚓缠绕，天地空阔，无可名状。从
这里往东北走就是天街，往西走便是月观峰，往北走则是到玉皇顶之路。
LONG );
	set("exits", ([
		"west"      : __DIR__"yueguan",
		"eastup"    : __DIR__"tianjie",
		"northup"   : __DIR__"yuhuang",
		"southdown" : __DIR__"jin18",
	]));
	set("item_desc", ([
		"lian" : "
门辟九霄，仰步三天胜迹  阶崇万级，俯临千嶂奇观\n",
	]));
	set("objects",([
		CLASS_D("taishan")+"/tianbai" : 1,
		__DIR__"npc/wei-shi3" : 2,
	]));
	set("outdoors", "taishan");
	set("coor/x", 360);
	set("coor/y", 770);
	set("coor/z", 200);
	setup();
	replace_program(ROOM);
}

