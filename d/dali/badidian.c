//Room: /d/dali/badidian.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","巴的甸");
	set("long",@LONG
这里就是大理西部要镇巴的甸，是乌夷的重要治府，多个乌夷部
落分布在附近。坐于东泸水谷地正中，巴的甸四周多农田，以此为中
心，道路四通八达连接各方的部落。
LONG);
	set("outdoors", "daliw");
	set("exits",([ /* sizeof() == 1 */
	    "north"      : __DIR__"zhenxiong",
	    "south"      : __DIR__"lushui",
	    "eastup"     : __DIR__"lushuieast",
	]));
	set("no_clean_up", 0);
	set("coor/x", -90000);
	set("coor/y", -70000);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}