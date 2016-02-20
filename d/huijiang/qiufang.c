// Room: /d/huijiang/qiufang.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "囚房");
	set("long",@LONG
这里是红花会关押叛徒和清狗的地方。门口大开着，也不怕要犯逃
跑掉。房间倒是打扫的很干净。铁窗上一丝蛛蛛网也见不着。
LONG );
	set("exits", ([
		"north" : __DIR__"zoulang3" ,
	]));
	set("objects", ([
		CLASS_D("honghua")+"/jiang-sigen" : 1,
	]));	
	set("coor/x", -50050);
	set("coor/y", 9130);
	set("coor/z", 10);
	setup();
}

int valid_leave(object me, string dir)
{
	if ( (dir == "north") &&
		((string)me->query("family/family_name") != "红花会") &&
		objectp(present("jiang sigen", environment(me))) &&
		(!present("honghua ling", me)))
	{
		me->receive_damage("qi", 15);
		me->receive_damage("jing", 5);
		return notify_fail("蒋四根拦住你说：非本会弟兄，私闯囚房，一定是清狗！\n"HIR"蒋四根不分青红皂白，先海扁了你一顿。\n"NOR);
	}
	return ::valid_leave(me, dir);
}
