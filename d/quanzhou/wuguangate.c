// Room: /d/quanzhou/wuguangate.c
// Last Modified by winder on May. 29 2001

inherit ROOM;

void create()
{
	set("short", "武馆大门");
	set("long", @LONG
一所气派辉煌的武馆。朱漆大门旁边摆镇了两头高大威猛，栩栩如
生的石狮子。门上挂着一块黑底大匾额，四个刷金的大字「扬威武馆」
闪闪生光。左边插着一根两丈多高的旗杆，绣着“武”字的红旗随风飘
扬。这便是城里招牌最老，威信最著的武馆，好多城中的子弟都在此学
些拳脚兵器功夫。馆主马五德豪富好客，颇有孟尝之风。所聘教头都是
一等一身具真功夫的好手。
LONG );
	set("outdoors", "quanzhou");
	set("exits", ([
		"west" : __DIR__"kaojiaochang",
		"east" : __DIR__"zhaiqu2",
	]));
	set("objects", ([
		__DIR__"npc/mengding" : 2,
	]));
	set("coor/x", 1830);
	set("coor/y", -6550);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
