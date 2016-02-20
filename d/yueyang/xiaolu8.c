// Room: /d/yueyang/xiaolu8.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "青石山道");
	set("long", @LONG
你正走在君山东麓通往秋月岭上的青石山道上。君山，由七十二峰
组成，峰峰皆灵秀，“烟波不动景沉沉，碧色全无翠色深。疑是水仙梳
洗处，一螺青黛镜中心。”但见野径苇叶离离、翠竹风响，满山的茶香。
不由得你心神俱醉，真是神仙洞府。
LONG );
	set("outdoors", "dongting");
	set("no_clean_up", 0);
	set("exits", ([
		"southwest" : __DIR__"qiuyueting",
		"enter"     : __DIR__"dongtingmiao1",
	]));
	set("coor/x", -1660);
	set("coor/y", 2350);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
