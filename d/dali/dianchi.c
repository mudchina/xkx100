//Room: /d/dali/dianchi.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","滇池");
	set("long",@LONG
滇池四周的山脉均属昆仑山系，云岭山脉的东支逶迤南下，总称乌蒙山，
有大小数十个山峰。湖身紧靠西山脚下，山环水抱，天光云影，构成天然的
图画。滇池的“滇”在彝语中即是大坝子，兼司马迁的《史记·西南夷列传》
记载，在古代就是这一地区的最大的部族名称，是名滇池。
LONG);
	set("outdoors", "dalic");
	set("exits",([ /* sizeof() == 1 */
	    "north"   : __DIR__"dasenlin",
	    "south"   : __DIR__"yanchi1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -35000);
	set("coor/y", -70300);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}