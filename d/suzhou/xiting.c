// Room: /d/suzhou/xiting.c
// Last Modified by Winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short", "西厅");
	set("long", @LONG
这里是衙门的西厅，乃是知府的书房。书案上凌乱地放着几本发黄
的古籍。引起你的注意的是墙上挂着一幅很大的地图(ditu)。
LONG
	);
	set("item_desc", ([
		"ditu" : "这是一幅苏州地区城防地图，上面有各种颜色的圈圈点点，显见主人经常\n看它，而且看得颇为仔细，似乎在寻找一个特别的地点。\n",	
	]));
	set("exits", ([
		"east" : __DIR__"yamen",
	]));
	set("no_clean_up", 0);
	set("coor/x", 835);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

