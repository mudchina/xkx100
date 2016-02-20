// Room: /d/yanping/youlang.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "十里游廊");
	set("long", @LONG
十里游廊穿行于溪源峡谷中。游廊风光漪丽，景色秀美。两岸石壁
对立，怪石嶙峋；峰回路转，山曲水迂；千屏万嶂，绵延起伏；树木森
郁，古藤缠绕。
LONG );
	set("exits", ([
		"southeast" : __DIR__"beimenling",
		"northwest" : __DIR__"xiagu",
	]));
	set("outdoors", "yanping");
	set("no_clean_up", 0);
	set("coor/x", 1450);
	set("coor/y", -6150);
	set("coor/z", 30);
	setup();
	replace_program(ROOM);
}
