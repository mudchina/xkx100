// Room: /d/yueyang/xijie.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "西街");
	set("long", @LONG
这是一条又长又宽的青石大道，马匹驰过，得得有声。行道两边一
些稀稀落落的树荫下，或坐或卧躺了些衣衫不整的人。岳阳为天下丐帮
总舵的常驻地，街面上三三两两的，乞丐成群往来不绝。各地的客商也
多来此蹭活。
    南面是个广场。北面是一栋大屋。
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"zhongxin",
		"west"  : __DIR__"ximen",
		"south" : __DIR__"guangchang",
		"north" : __DIR__"gaibanggate",
	]));
	set("objects", ([
		CLASS_D("gaibang")+"/chen-guyan" : 1,
		CLASS_D("gaibang")+"/bangzhong" : 1,
	]));
	set("coor/x", -1420);
	set("coor/y", -2270);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
