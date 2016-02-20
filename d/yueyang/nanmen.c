// Room: /d/yueyang/nanmen.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "岳阳南门");
	set("long", @LONG
这里是岳阳城的南门。青石筑成两层楼台坚固异常，巍峨宽阔的拱
形城门上方，镂着「岳阳」两个红漆大字。南面是一条林荫大道，通向
衡阳。
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("objects", ([
		CLASS_D("gaibang")+"/bangzhong" : 3,
		CLASS_D("gaibang")+"/li-chunlai" : 1,
	]));
	set("exits", ([
		"north"     : __DIR__"nanjie",
		"southeast" : "/d/henshan/hsroad8",
	]));
	set("coor/x", -1410);
	set("coor/y", -2290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
