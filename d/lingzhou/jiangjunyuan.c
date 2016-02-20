// Room: /lingzhou/jiangjunyuan.c
// Java. Sep 21 1998

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "将军府大院");
	set("long", @LONG
这里是将军府的大院，当面一堵宽阔的白玉照壁，上书“忠心报国”
四个大字，落款是当今西夏皇帝李元昊。一色的青砖铺地，有几个仆役
正在院中洒扫，南面是内宅，西面是帐房，东面是个小院。
LONG );
	set("exits", ([
//		"east"  : __DIR__"xiaoyuan",
//		"west"  : __DIR__"zhangfang",
//		"enter" : __DIR__"neizai",
		"north" : __DIR__"jiangjungate",
	]));
	set("no_fight",1);
	set("objects", ([
		"/d/city/npc/jiading" : 2,
	]));
	set("coor/x", -17950);
	set("coor/y", 32050);
	set("coor/z", 0);
	setup();
	create_door("north" , "油木大门", "south" , DOOR_CLOSED);
//	create_door("south" , "卷帘门", "north" , DOOR_CLOSED);
}

int valid_leave(object me, string dir)
{
        if (dir == "south" && 
            objectp(present("xiao wei", environment(me))))
           return notify_fail("校尉挡住了你的去路：大将军不在府上！\n");

        return ::valid_leave(me, dir);
}