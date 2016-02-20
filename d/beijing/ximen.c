// Room: /beijing/ximen.c

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "西门");
	set("long", @LONG
这是西城门，几年前曾经遭到土匪的攻打，因此显得有些破败。城
门正上方勉勉强强可以认出“西门”两个大字，城墙上贴着几张通缉告
示(gaoshi)。罪犯常常从这里逃出京城，官兵们戒备森严，动不动就截
住行人盘问。一条笔直的青石板大道向东西两边延伸。西边是郊外，骑
马的、坐轿的、走路的，行人匆匆。东边是城里。
LONG );
        set("outdoors", "beijing");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));
	set("exits", ([
		"east" : __DIR__"xichang2",
		"west" : __DIR__"ximenwai",
	]));
        set("objects", ([
                "/d/city/npc/wujiang" : 1,
                "/d/city/npc/bing" : 2,
        ]));
	set("coor/x", -230);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return "辑拿天地会一众反贼! \n举报一人，赏金十两;\n"
          "捉拿一人，赏金百两。\n知情不报者，立斩!\n鳌拜发\n";
}
