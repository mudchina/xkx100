// Room: /d/hengshan/xuankong1.c
// Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short", "悬空寺北楼");
	set("long", @LONG
这里是悬空寺的北门楼，也是北碑亭。登楼俯视，如临深渊，谷底
仰望，如壁间丹凤。向南有悬空栈桥通往南楼。
LONG
	);
	set("exits", ([
		"south"    : __DIR__"zhanqiao",
		"up"       : __DIR__"sanjiaodian",
		"westdown" : __DIR__"cuiping2",
	]));
	set("objects", ([
		__DIR__"npc/yafu" : 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 0);
	set("coor/y", 3180);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}

