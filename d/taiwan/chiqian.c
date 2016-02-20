// Room: /d/taiwan/chiqiancheng.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "赤嵌城");
	set("long", @LONG
赤嵌城位于台南地区，为台湾府驻所。荷兰人安平筑热兰遮城后，
为巩固政权，乃于一六五三年在台南地区再筑新城，与热兰遮城互为犄
角，名为普罗文查城，汉人称之为「赤嵌城」或「红毛楼」。一六六二
年，国姓爷驱荷，在赤嵌城设东都「承天府治」。
    台湾归清后，清廷大臣多主张弃守，唯征台将军施琅力言：「弃之
必酿大祸，留之永固边围。」终得保留，隔年，并将台湾府治设于台南
赤嵌城。
LONG );
	set("exits", ([
		"east"  : __DIR__"donganfang",
		"west"  : __DIR__"xidingfang",
		"south" : __DIR__"ningnanfang",
		"north" : __DIR__"zhenbeifang",
	]));
	set("objects", ([
		__DIR__"npc/bing": 2,
		__DIR__"npc/shilang": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2510);
	set("coor/y", -7050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

