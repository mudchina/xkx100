// Room: /d/taishan/xitian.c
// Last Modified by Winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "西天门");
	set("long", @LONG
月观峰山阴有两块巨石壁立如门，有如给人斩削过似的，正是岱顶
的西面出口，称西天门。明万历年间林古度在石门上题“西阙”。钟惺
在《登泰山记》中颂道：“岱之为天门者三，西天门者石自门焉，真天
门也。”
LONG );
	set("exits", ([
		"southdown" : __DIR__"yueguan",
	]));
	set("objects", ([
		CLASS_D("taishan")+"/yuqingzi" : 1,
	]));
	set("no_clean_up", 0);
	set("outdoors", "taishan");
	set("coor/x", 350);
	set("coor/y", 780);
	set("coor/z", 210);
	setup();
	replace_program(ROOM);
}
