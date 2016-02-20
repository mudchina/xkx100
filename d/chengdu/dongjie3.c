// Room: /d/chengdu/dongjie3.c
// Last Modifyed by Winder on Jan. 4 2002

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
这条街贯穿成都大街小巷，因这条街沿街都是有钱有势的酒楼、茶
馆，所以又称为“美食街”。这里店铺林立，商贾成群。白天这里车马
如龙，人声鼎沸，夜里星光伴月，灯火通明。南边是个茶馆，北边有个
水井。
LONG	);
	set("outdoors", "chengdu");
	set("exits", ([
		"east"  : __DIR__"eastgate",
		"west"  : __DIR__"dongjie2",
		"north" : __DIR__"shuijing",
		"south" : __DIR__"chaguan3",
	]));
	set("objects", ([
		__DIR__"npc/youke" : 1,
	]));
	set("coor/x", -8020);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

