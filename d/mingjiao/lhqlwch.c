// lhqlwch.c

inherit ROOM;

void create()
{
	set("short", "练武场");
	set("long", @LONG
你走进了烈火旗的练武场，发现练武的教众们并不是在相互切磋武
功，而是穿戴着特制的防火护具，在学习使用火具和瞄准。火具中喷出
黝黑的原油，见火即燃，威力无比。
LONG );
	set("exits", ([
		"east" : __DIR__"lhqyuan",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52040);
	set("coor/y", 1000);
	set("coor/z", 60);
	setup();
	replace_program(ROOM);
}