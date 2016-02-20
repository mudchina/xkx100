// Room: /d/yueyang/beimen.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "岳阳北门");
	set("long", @LONG
这里是岳阳城的北门。青石筑成两层楼台坚固异常，巍峨宽阔的拱
形城门上方，镂着「岳阳」两个红漆大字。北面是一条黄土路，直通江
陵。
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"beijie",
		"northwest" : "/d/jiangling/tulu2",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/bangzhong" : 1,
	]));
	set("coor/x", -1410);
	set("coor/y", -2250);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
