#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "大院");
	set("long", @LONG
这是一个破旧的大院。院内十分宽阔，可容百人。正中一口天井，
再往里是座大厅。
LONG );
	set("exits", ([
		"north" : __DIR__"zhuang5",
		"south" : __DIR__"zhuang3",
	]));
	set("objects", ([
		"/d/shenlong/npc/zhang3": 1,
	]));
	set("outdoors", "huabei");
	set("coor/x", 100);
	set("coor/y", 4710);
	set("coor/z", 0);
	setup();
	replace_program(ROOM); 
}
