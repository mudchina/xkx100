// Room: /d/yueyang/xiaolu6.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "引道");
	set("long", @LONG
你走在君山东麓的湘妃祠引道上。君山，由七十二峰组成，峰峰皆
灵秀，“烟波不动景沉沉，碧色全无翠色深。疑是水仙梳洗处，一螺青
黛镜中心。”但见野径苇叶离离、翠竹风响，满山的茶香。不由得你心
神俱醉，真是神仙洞府。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"enter"     : __DIR__"xiangfeici1",
		"northwest" : __DIR__"xiaolu7",
		"southwest" : __DIR__"erfeimu",
	]));
	set("coor/x", -1660);
	set("coor/y", 2310);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
