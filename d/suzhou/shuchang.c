// Room: /d/suzhou/shuchang.c
// Date: May 31, 98  Java
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "书场");
	set("long", @LONG
你走进书场，看见里面热热闹闹的，场子里都是听书的，场子前面
有一位说书先生，他看上去四五十岁，手中拿着一块响板，正在聚精会
神地说着评书--《杨家将》。你也逐渐被评书的内容所吸引，场中的人
们不时的发出惊叹和喝彩声，时不时将铜板抛了上去。
LONG );
	set("outdoors", "suzhou");
	set("item_desc", ([
		"door" : "这是一扇通往后堂的小木门。\n"
	]));
	set("exits", ([
		"south" : __DIR__"xidajie2",
		"enter" : __DIR__"houtang",
	]));
	set("objects", ([
		__DIR__"npc/gongzi": 1,
	]));
	set("coor/x", 830);
	set("coor/y", -1000);
	set("coor/z", 0);
	create_door("enter", "小门", "out", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}
