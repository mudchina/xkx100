// Room: /d/baituo/huayuan.c
// Last Modified by winder on May. 15 2001

inherit ROOM;

void create()
{
	set("short", "大花园");
	set("long", @LONG
这是个美丽的大花园，园子里面种着鲜艳的红玫瑰。白衣少女常来
这里嬉戏。沿着弯弯曲曲的花径，可以通到山庄的许多地方。东边是厨
房。西边是白驼山少主『欧阳克』的内室，门虚掩着，不知主人在不在。
LONG	);
	set("exits",([
		"west"  : __DIR__"neishi",
		"north" : __DIR__"zhuyuan",
		"east"  : __DIR__"chufang",
		"south" : __DIR__"tuitang",
	]));
	set("outdoors", "baituo");
	set("objects",([
		__DIR__"npc/whitelady" : 2,
	]));
	set("coor/x", -50010);
	set("coor/y", 20060);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}




