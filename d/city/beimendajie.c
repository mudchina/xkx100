// Room: /yangzhou/beimendajie.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short", "北门大街");
	set("long", @LONG
北门街宽约二十丈，中间以槐树隔开，行人分行左右。街边有排水
沟直接通向官河。街西是大虹桥，街东通向琼花街。北边是扬州的北门
「镇淮门」。街东边是名扬天下的崇雅书院，隐隐可以听到朗朗的读书
声。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"hongqiao",
		"east"  : __DIR__"qionghuajie",
		"south" : __DIR__"shilijie1",
		"north" : __DIR__"beimen",
	]));
	set("objects", ([
		__DIR__"npc/geji" : 1,
	]));
	set("coor/x", 10);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}