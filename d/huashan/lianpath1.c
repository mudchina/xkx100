//Roon: lianpath1.c 莲花峰小路
//Date: Oct. 2 1997 by Venus

inherit ROOM;

void create()
{
	set("short","莲花峰小路");
	set("long",@LONG
小路通往莲花峰，周围静静悄悄，微闻蝉鸣。四望密林幽谷，让人胆
寒。
LONG);
	set("outdoors", "huashan");
	set("exits",([ /* sizeof() == 1 */
		"westup"   : __DIR__"lianpath2",
		"northeast": __DIR__"zhenyue",
	]));
	set("objects",([ 
		__DIR__"npc/ying-bailuo" : 1,
	]));
	set("coor/x", -880);
	set("coor/y", 180);
	set("coor/z", 110);
	setup();
	replace_program(ROOM);
}
