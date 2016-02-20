// Room: /d/changcheng/badaling.c
// Last Modified by Winder on Aug. 25 2000

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "八达岭");
	set("long", WHT@LONG
八达岭为居庸关外口，关城建于两山之间。关城有二门，东门额题
“居庸外镇”，西门额题“北门锁钥”。登上关楼，向西眺望，只见崇
山峻岭，层峦叠嶂，群山之中只有八达岭城关这个缺口，大有“一夫当
关，万夫莫开”的气势。
LONG
NOR  );
	set("outdoors", "changcheng");
	set("exits", ([
		"west"      :__DIR__"juyongguan",
		"northeast" :__DIR__"beisilou",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
	]));
	set("coor/x", 1000);
	set("coor/y", 5000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}