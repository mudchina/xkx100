// Room: /d/wuxi/road4.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
快马加鞭，走在江南平坦的驿道上，微风拂面，扬柳摇摆，心情
也变得十分愉快。驿道直直地向东西方延伸过去。向东远远地就已经
看见苏州的北平门了，道上的行人也多了不少。
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"southeast"  : "/d/suzhou/road1",
		"west"       : __DIR__"road3",
	]));
	set("coor/x", 800);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}