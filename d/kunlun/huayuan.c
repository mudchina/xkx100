// Room: /d/kunlun/huayuan.c
// Last Modified by winder on Nov. 15 2000

inherit ROOM;

void create()
{
	set("short", "后花园");
	set("long", @LONG
这里是昆仑派的后花园。园内有方池，缘池是座假山。廊边花木扶
疏，竹影参差，山泉急湍，竟然富有江南园林的情趣。西面是昆仑派的
侧门。
LONG );
	set("exits", ([
		"west"      :__DIR__"cemen",
		"east"      : __DIR__"huapu",
		"south"     : __DIR__"houting",
		"north"     : __DIR__"shanlin1",
		"southeast" : __DIR__"jiashan",
		"southwest" : __DIR__"liangting",
	]));

	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	set("coor/x", -119990);
	set("coor/y", 40130);
	set("coor/z", 90);
	setup();
	replace_program(ROOM);
}