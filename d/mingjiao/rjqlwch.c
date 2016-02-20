//RJQLWCH.C

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
走进了锐金旗的练武场，发现这里有些奇怪。练武的教众们并不是
在相互切磋，而是穿戴着特制的护具，同一架奇怪的装置打斗。装置从
不移开原地，只是它似乎具备用不完的各种兵器，进攻起来丝毫不弱于
江湖好手。
LONG );
	set("exits", ([
		"north" : __DIR__"rjqyuan",
	]));

	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52020);
	set("coor/y", 850);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}