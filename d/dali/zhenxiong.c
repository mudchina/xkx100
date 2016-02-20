//Room: /d/dali/zhenxiong.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","镇雄");
	set("long",@LONG
这里是乌撒部的聚居中心，乌撒是乌蛮族的大部，属乌夷，领有
巴的甸、镇雄、和附近的威宁。这是一座石砌小城，人口不多，居民
散居在镇子附近，镇子上主要是一些商铺和祭祀所。
LONG);
	set("objects", ([
	   __DIR__"npc/muyangnu": 1,
	   __DIR__"npc/wshangfan": 1,
	]));
	set("outdoors", "daliw");
	set("exits",([ /* sizeof() == 1 */
	    "south"      : __DIR__"badidian",
	    "north"      : __DIR__"gelucheng",
	    "northeast"  : __DIR__"minadian",
	    "east"       : __DIR__"titian1",
	    "west"       : __DIR__"wuyiminju3",
	]));
	set("coor/x", -90000);
	set("coor/y", -69990);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}