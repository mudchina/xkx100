// Room: /d/nanshaolin/huaishu4.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "槐树林");
	set("long", @LONG
眼前一暗你走进一片槐树林，枝头鸟语轻鸣，荫下清风荡漾。好一
个清净禅修之所在。林中一条小径曲折伸向前方。
LONG
	);
	set("outdoors","nanshaolin");
	set("exits", ([
		"east"  : __DIR__ "stoneroad1",
		"west"  : __DIR__ "slyuan",
		"north" : __DIR__ "huaishu5",
		"south" : __DIR__ "huaishu2", 
	]));
	set("coor/x", 1800);
	set("coor/y", -6210);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

