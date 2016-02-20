// Room: /yangzhou/tongsiqiao.c
// Last Modified by Winder on Jul. 20 2000

inherit ROOM;

void create()
{
	set("short","通泗桥");
	set("long",@LONG
通泗桥连接扬州旧城的中心十里街和官衙，宽敞平整，数辆大车可
以并行。桥的西头围出一大花坛，种着扬州的名花「芍药」(shaoyao)，
更有一株老杏，横卧水上，夭矫屈曲。桥的东头，立一巨石，上书「通
泗桥」。桥上常有行人倚栏笑看船儿桥下过。
LONG );
	set("outdoors", "yangzhouw");

	set("exits", ([
		"west"  : __DIR__"caohexiaojie",
		"east"  : __DIR__"shilijie4",
	]));
	set("item_desc", ([
		"saoyao" : "扬州以盛产芍药而名闻天下，其中又以「金带围」最为名贵。\n",
	]));
	set("objects", ([
		__DIR__"npc/liuyan" : 1,
	]));
	set("coor/x", 0);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}