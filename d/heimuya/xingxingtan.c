// Room: /d/heimuya/xingxingtan.c
// Last Modified by winder on Apr. 10 2000

inherit ROOM;

void create()
{
	set("short", "猩猩滩");
	set("long", @LONG
只见一片长滩，山石殷红如血，水流湍急，这便是有名的猩猩滩。
一叶小舟隐藏在芦苇中，要过对面就要靠这几艘小船了。
LONG );
	set("outdoors", "heimuya");
	set("objects", ([
//		CLASS_D("heimuya")+"/first" : 1,
	]));
	set("exits", ([
		"eastup" : __DIR__"shidao2",
		"enter"  : __DIR__"duchuan1",
	]));
	set("coor/x", -3060);
	set("coor/y", 4040);
	set("coor/z", -10);
	setup();
}

int valid_leave(object me, string dir)
{
	if( dir != "enter" ) me->set_temp("hmy_ship/xxt", 1);
	else me->delete_temp("hmy_ship");
	return ::valid_leave(me, dir);
}
