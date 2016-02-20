// Room: /d/huangshan/qingluan.c
// Last Modified by winder on Sep. 27 2001

inherit ROOM;
void create()
{
	set("short", "青鸾桥");
	set("long", @LONG
说是青鸾桥，确切的应该是倚山势看上去是桥，实际上却是一座石
梁，远望去好似青鸾腾空，背上可以行人，石梁左侧刻有“青鸾”二字，
北去便是黄山三名瀑之“百丈泉”，西行便是半山寺了。
LONG
	);
	set("exits", ([ 
		"east"      : __DIR__"baizhang",
		"west"      : __DIR__"renzi",
		"southup"   : __DIR__"ciguang",
		"northup"   : __DIR__"banshan",
		"northwest" : __DIR__"zuishi",
	]));
	set("objects", ([
		__DIR__"obj/stone" : 1,
	]) );
	set("outdoors", "huangshan");
	setup();
	replace_program(ROOM);
}
