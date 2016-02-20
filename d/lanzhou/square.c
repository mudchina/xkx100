//  Room:  /d/lanzhou/square.c

inherit  ROOM;

void  create  ()
{
	set("short",  "城隍庙广场");
	set("long",  @LONG
西北第一大城，既是西北的经济中心，也是文化中心。兰州的文化
集各家丰采，既有传统的释、道、儒三家影响，也有回教的投影，比起
京城、扬州，细腻稍有不足，但飞扬之势却有过之。
    这里是城隍庙前的一个广场。适逢庙会，人群熙熙攘攘。广场上卖
艺的、算命的、做小买卖的不停的打你钱包主意。东边是本城的集市，
西边则通往附近百里仅有的贡院。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"south" : __DIR__"road2",
		"north" : __DIR__"street2",
		"east"  : __DIR__"market",
		"west"  : __DIR__"cuiying",
	]));
	set("outdoors", "lanzhou");
	set("no_clean_up", 0);
	set("coor/x", -9290);
	set("coor/y", 2690);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}