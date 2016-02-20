// /beijing/weifu_men.c
// Last modified by winder 2003.10.10

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short","韦府大门");
	set("long", @LONG
这里便是当朝第一宠臣，被康熙帝御封为“一等鹿鼎公”的韦公爷
的居宅。来到这里，一座富丽堂皇的高大建筑出现在你的眼前，大门两
侧是两头高大的石狮子。门上横着一块大匾，上面是当朝首辅、户部尚
书兼保和殿李大学士亲笔工楷的“鹿鼎公府”四个金笔大字。
    门前站着个韦府的侍卫。
LONG );
	set("exits", ([
		"north" : __DIR__"weifu_zoulang1",
		"south" : __DIR__"xisi2",
	]));
	set("objects", ([
		__DIR__"npc/shiwei2" : 1,
	]));
	set("coor/x", -220);
	set("coor/y", 4090);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (objectp(present("shi wei", environment(me))) && dir == "north")
		return notify_fail("侍卫喝道：别乱逛，公爷今天不见客。\n\n");
	return ::valid_leave(me, dir);
}
