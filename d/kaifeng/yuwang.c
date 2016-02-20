// /kaifeng/yuwang.c
// Last modified by winder 2003.10.20

inherit ROOM;

void create()
{
	set("short", "禹王台");
	set("long", @LONG
禹王台建造于小山丘之上，这里风景优美，环境幽雅，自古以来就
是人们游春登高的胜地。相传春秋时期，晋国盲人乐师旷常在此吹奏古
乐，故名『吹台』。
LONG);
	set("objects", ([
		__DIR__"npc/woman" : 1,
	]));
	set("exits", ([
		"west"   : __DIR__"shulin",
		"eastup" : __DIR__"yuwangmiao",
	]));
	set("outdoors", "kaifeng");

	setup();
	replace_program(ROOM);
}
