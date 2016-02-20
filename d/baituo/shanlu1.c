// Room: /d/baituo/shanlu1.c
// Last Modified by winder on May. 15 2001
inherit ROOM;

void create()
{
	set("short","山路");
	set("long", @LONG
这里是山上的泥路。四周是一眼望不尽的丛林。这里地处西域，天
候干燥，山风刮来，一片片的树林左右摇摆。
LONG);
	set("exits",([
		"north" : __DIR__"shulin",
		"southeast" : __DIR__"shanlu",
	]));
	set("outdoors", "baituo");
	set("objects" ,([
		__DIR__"npc/qiaofu" : 1 ,
	]) );
	set("coor/x", -50030);
	set("coor/y", 20010);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
