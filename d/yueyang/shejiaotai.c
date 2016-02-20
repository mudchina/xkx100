// Room: /d/yueyang/shejiaotai.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "射蛟台");
	set("long", @LONG
射蛟台又名射蛟浦，在酒香亭东面。这是一悬空而立横卧洞庭湖中
的巨石。相传汉代有一巨蛟，在水中兴风作浪，劳命伤财，汉武帝闻之
便率兵巡狩，在君山射蛟于浦口。巨石顶上有个三米见方平面，上有两
个二尺多长的巨大脚印，传为汉武帝射蛟时留下的圣迹，此台集幽峭、
险峻于一体，为君山八景之一。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"east"   : __DIR__"xiaolu2",
		"westup" : __DIR__"shijie3",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/song" : 1,
	]));
	set("coor/x", -1740);
	set("coor/y", 2280);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
