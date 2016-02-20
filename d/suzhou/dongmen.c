// Room: /d/suzhou/dongmen.c
// Date: May 31, 98  Java

inherit ROOM;

string look_gaoshi();
void create()
{
	set("short", "相门");
	set("long", @LONG
这是号称天堂的苏州东城门，城门正上方刻着“相门”两个楷书大
字，城墙上贴着几张官府告示(gaoshi)。守门官兵们警惕地注视着过往
行人，你最好小心为妙。一条笔直的青石板大道向东西两边延伸，西边
是城里。
LONG );
	set("outdoors", "suzhou");
//	set("no_clean_up", 0);
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"west" : __DIR__"dongdajie2",
		"east" : "/d/jiaxing/jnroad2",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", 900);
	set("coor/y", -1000);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n苏州知府\n冯旭东\n";
}
