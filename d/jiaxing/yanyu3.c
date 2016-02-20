// Room: /d/jiaxing/Yanyu3.c  烟雨楼顶
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "烟雨楼顶");
	set("long", @LONG
这里是烟雨楼的楼顶，放眼一片空阔，东西两湖如鸳鸯交颈，轻烟
拂渚，微雨欲来，晓霭迷蒙，正是历代文人骚客把酒凭栏、吊古吟咏的
好所在。
LONG );
	set("no_sleep_room",1);
	
	set("exits", ([
	    "down"     : __DIR__"yanyu2",
	]));
	
	set("objects", ([
		CLASS_D("baituo")+"/ouyangfeng1": 1
	]));
	set("coor/x", 1520);
	set("coor/y", -1020);
	set("coor/z", 20);
	setup();
}

