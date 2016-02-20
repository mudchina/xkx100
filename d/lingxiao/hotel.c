// Room: /d/lingxiao/hotel.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "冰雪轩");
	set("long", @LONG
这里是凌霄城里最大的酒楼冰雪轩，同时也是凌霄城的名迹之一。
大凡过往旅客，不管是贩夫走卒，还是文人墨客，迁客骚人，都要到此
一醉。当年谢烟客独闯凌霄城，在此狂饮十八坛烈酒之后，杀入凌霄内
城。从此，凌霄城冰雪轩的大名，便是名闻四海。
LONG );
	set("exits", ([
		"east" : __DIR__"iceroad1",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
		__DIR__"npc/dizi" : 2,
	]));
	set("coor/x", -31010);
	set("coor/y", -8920);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

