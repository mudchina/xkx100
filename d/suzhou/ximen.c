// Room: /d/suzhou/ximen.c
// Date: May 31, 98  Java

inherit ROOM;

string look_gaoshi();
void create()
{
	set("short", "阊门");
	set("long", @LONG
这是号称天堂的苏州西城门，城门正上方刻着“阊门”两个楷书大
字，城墙上贴着几张官府告示(gaoshi)。西门外通向寒山寺一条笔直的
青石板大道向东西两边延伸，东边是城里。
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"west" : __DIR__"road2",
		"east" : __DIR__"xidajie2",
	]));
        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
        ]));
	set("coor/x", 820);
	set("coor/y", -1010);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n苏州知府\n冯旭东\n";
}
