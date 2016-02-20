// Room: /d/yueyang/xiaolu1.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在君山东麓的湖边小路上。君山，由七十二峰组成，峰峰皆灵
秀，“烟波不动景沉沉，碧色全无翠色深。疑是水仙梳洗处，一螺青黛
镜中心。”但见野径苇叶离离、翠竹风响，满山的茶香。不由得你心神
俱醉，真是神仙洞府。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"south"     : __DIR__"matou",
		"northwest" : __DIR__"longkou",
		"southeast" : __DIR__"fengshanyin",
	]));
	set("coor/x", -1710);
	set("coor/y", 2280);
	set("coor/z", -20);
	setup();
	replace_program(ROOM);
}
