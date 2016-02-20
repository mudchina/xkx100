// Room: /d/xingxiu/shuiliandong.c
// Last Modified by winder on Apr. 25 2001

inherit ROOM;

void create()
{
	set("short", "水帘洞");
	set("long", @LONG
这里群峰高耸，沿曲径入幽林，峰回路转，石壁中露出有拱形洞窟，洞内
水锈青苔，红绿班驳，乱石穿孔。雨季山顶飞流直下如水帘，因有此名。
LONG);
	set("outdoors", "silu");
	set("exits", ([
		"southeast" : __DIR__"xianrenya",
		"northeast" : __DIR__"chouchishan",
	]));
	set("no_clean_up", 0);
	set("coor/x", -21000);
	set("coor/y", 400);
	set("coor/z", 0);
	setup();
//	replace_program(ROOM);
}

#include "/d/xingxiu/job2.h";

