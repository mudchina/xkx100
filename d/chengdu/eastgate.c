// Room: eastgate.c
// Date: Feb.14 1998 by Java

inherit ROOM;
string look_gaoshi();
void create()
{
	set("short", "东城门");
	set("long", @LONG
这是成都东城门，城门正上方刻着“东门”两个楷书大字，城墙上
贴着几张官府告示(gaoshi)。一条笔直的青石板大道向东西两边延伸。
东边是郊外，一片平平展展的平原风光，真是不愧天府之国的美称。西
边是城里。
LONG	);
	set("outdoors", "chengdu");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east"  : __DIR__"fuheqiaoe",
		"west"  : __DIR__"dongjie3",
	]));
	set("objects", ([
		__DIR__"npc/wujiang" : 1,
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -8010);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n成都提督\n吴天德\n";
}
