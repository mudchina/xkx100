// maojiabu.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "茅家埠");
        set("long", @LONG
路两旁盖着几座小土房。房门口一位老大娘正在喂鸡，几个小孩
正在追逐嬉戏。北边是上黄泥岭。南面是丁家山。
LONG);
        set("exits", ([
            "southwest"   : __DIR__"tulu1",
            "northup"     : __DIR__"huangniling",
        ]));
        set("objects", ([
            __DIR__"npc/boy" : 1,
            __DIR__"npc/oldwoman" : 1,
            __DIR__"npc/camel" : 1,
        ]));
        set("outdoors", "hangzhou");
	set("coor/x", 2700);
	set("coor/y", -1500);
	set("coor/z", 0);
	setup();
        replace_program(ROOM);
}
