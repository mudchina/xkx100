// Room: /d/taishan/hongmen.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;

void create()
{
	set("short", "弥勒院");
	set("long", @LONG
弥勒院由祀观音大士之飞云阁与红门宫相连。东院正殿原祀木雕弥
勒佛；东有穿堂式更衣亭，旧时帝王官宦登山至此更衣；南有穿堂式过
庭。
LONG );
	set("exits", ([
		"west"      : __DIR__"hongmen",
		"southeast" : __DIR__"bailuo",
	]));
	set("outdoors", "taishan");
	set("no_clean_up", 0);
	set("coor/x", 410);
	set("coor/y", 550);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
