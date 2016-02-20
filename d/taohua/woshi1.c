// Room: /d/taohua/woshi1.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "蓉香榭");
	set("long", @LONG
你走进了一间卧房。一股若有若无的甜香扑鼻而来。琴剑书画，挂
在墙上。锦笼纱罩，金彩珠光。小几上汝窑美人瓶内的桃花正自盛开。
右首一张床，床头放着五彩鸾纹被。
LONG );
	set("exits", ([
		"west" : __DIR__"neishi1",
	]));
	set("objects", ([
		CLASS_D("taohua")+"/rong" : 1,
		__DIR__"npc/binu" : 2,
	]) );
	set("coor/x", 9010);
	set("coor/y", -2980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}