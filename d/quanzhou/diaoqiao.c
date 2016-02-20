// Room: /d/quanzhou/diaoqiao.c
// Last Modified by winder on May. 29 2001

inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "新门吊桥");
	set("long", @LONG
这是泉州西面的一座吊桥，从傍着晋河而建的城楼大门上以两个滑
轮维系。日出放下吊桥，日落绞起。城楼墙上有张官府告示(gaoshi)。
西出城门便是乱石岗，经常有土匪出没，没事还是别出城的好。
LONG );
	set("outdoors", "quanzhou");
	set("no_clean_up", 0);
        set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
        ]));
	set("exits", ([
		"west" : __DIR__"luanshigang",
		"east" : __DIR__"xinmenji",
	]));
	set("coor/x", 1830);
	set("coor/y", -6580);
	set("coor/z", 0);
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n靖海将军\n施琅\n";
}
