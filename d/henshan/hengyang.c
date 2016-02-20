// Room: /d/henshan/hengyang.c
// Modified by Java on Feb.14.1998

inherit ROOM;

void create()
{
	set("short", "衡阳城");
	set("long", @LONG
这里就是衡阳县城。衡阳地处偏远，显见远不如中原繁华了。
LONG );
	set("outdoors", "hengyang");
	set("exits", ([
		"east"   : __DIR__"hsroad3",
		"west"   : __DIR__"hengyang1",
		"south"  : __DIR__"chaguan",
		"north"  : __DIR__"lingxingmen",
	]));
	set("objects", ([
		CLASS_D("henshan")+"/lu":1,
	]));
//        set("no_clean_up", 0);
	set("coor/x", -300);
	set("coor/y", -1200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
