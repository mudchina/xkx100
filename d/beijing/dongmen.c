// Room: /beijing/dongmen.c

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "东门");
	set("long", @LONG
这是东城门，城门正上方刻着“东门”两个大字，城墙上贴着几张
官府告示(gaoshi)。一条笔直的青石板大道向东西两边延伸。东边是郊
外，越过城门可以看到驿道上人来车往，尘土飞扬。西边通往城里。西
北边是朝阳门。
LONG );
	set("outdoors", "beijing");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east"  : __DIR__"road1",
		"west"  : __DIR__"dongcha2",
		"south" : __DIR__"matou",
	]));
	set("objects", ([
		"/d/city/npc/wujiang" : 1,
		"/d/city/npc/bing" : 2,
	]));
	set("coor/x", -170);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return "辑拿天地会一众反贼! \n举报一人，赏金十两;\n"
          "捉拿一人，赏金百两。\n知情不报者，立斩!\n鳌拜发\n";
}
