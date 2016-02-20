//Room: /d/dali/bijishan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","碧鸡山顶");
	set("long",@LONG
碧鸡山坐在滇池的西岸上，与拓东城隔水相望。山势高耸入云，
山形有如公鸡，漫山树木苍翠欲滴。此处乃是极顶，已达云端，东眺
滇池一片汪洋，美不胜收。山下属大理国的昆州。东西皆有下山之路。
LONG);
	set("objects", ([
	   __DIR__"npc/youke": 1,
	]));
	set("outdoors", "dalic");
	set("exits",([ /* sizeof() == 1 */
	    "westdown"  : __DIR__"qingxi",
	    "eastdown"  : __DIR__"yanan2",
	]));
	set("coor/x", -36000);
	set("coor/y", -70980);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}