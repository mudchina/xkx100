// Room: /d/wuxi/guangchang.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "三阳广场");
	set("long", @LONG
这是无锡的正中心，一个很宽阔的广场，都是用很大很整齐的青石
铺成，关于这里为什么叫做“三阳”，却没人说得上来了。一些游手好
闲的人在这里溜溜达达。你可以看到北边有来自各地的行人来来往往，
南面人声鼎沸，一派繁华景象，西边好象很热闹，东边则有些肃静。
LONG );
	set("outdoors", "wuxi");
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"northroad1",
		"south" : __DIR__"southroad1",
		"east"  : __DIR__"eastroad1",
		"west"  : __DIR__"westroad1",
	]));
	set("coor/x", 370);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}