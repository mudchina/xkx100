// Room: /d/huijiang/damen.c
// Last Modified by winder on Sep. 12 2001

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "总舵大门");
	set("long",@LONG
你站在两扇红漆大门前，门上钉满的碗口大小的铜钉，门口的台阶
上叉腰站着两个膀阔腰圆的大汉，往里看去可以看见一条蜿延曲折的走
廊通向房屋深处。
LONG );
	set("outdoors", "huijiang");
	set("exits", ([
		"enter" : __DIR__"zoulang1" ,
		"south" : __DIR__"xiagu",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 2,
		CLASS_D("honghua")+"/wen-tailai" : 1,
		CLASS_D("honghua")+"/luo-bing" : 1,
	]));	
	set("coor/x", -50060);
	set("coor/y", 9140);
	set("coor/z", 0);
	setup();
}

void init()
{
	object me = this_player();
	if ( interactive( this_player()) &&
		((string)me->query("family/family_name") != "红花会") &&
		(!present("honghua ling", me)))
		message_vision(HIG"两个大汉向$N瞪了一眼，鼻子里重重的哼了一声！\n"NOR,me);
	else
		if ( present("honghua ling",me) &&
			!(present("honghua ling",me))->query("zizhi")) 
			message_vision(HIG"两个大汉躬身向你行了个礼,说道：令主好！\n"NOR,me);
}

int valid_leave(object me, string dir)
{
	if ( (dir == "enter") &&
		((string)me->query("family/family_name") != "红花会") &&
		objectp(present("wen tailai", environment(me))) &&
		(!present("honghua ling", me)))
		return notify_fail("文泰来拦住你说：非本会弟兄，不能进去！\n");
	return ::valid_leave(me, dir);
}
