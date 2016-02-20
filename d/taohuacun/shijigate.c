// /d/taohuacun/shijigate.c
// Last Modifiedy by Zeratul June 2000

inherit ROOM;

void  create()
{
	set( "short", "桃花集门" );
	set( "long", @LONG
北边新开了一个市集，四面八方的商贩都聚集到此处，好不热闹。
市集里熙熙攘攘的人声不时传入你的耳中，惹的你心痒痒的，忍不住
想进去瞧瞧。
LONG
	);
	set( "exits", ([
		"north" : __DIR__"shiji1",	
		"south" : __DIR__"taohua6",	
	]));
        set("outdoors", "taohuacun");		
	set("coor/x", -100);
	set("coor/y", 30);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}