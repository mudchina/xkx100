inherit ROOM;

void create()
{
	set("short", "康府内堂");
	set("long", @LONG
这里是康府内堂，一个仆役正在和丫环们聊天。南边是康府
后院，北边是书房，西边是一座佛堂。
LONG );
	set("exits", ([
  		"west"  : __DIR__"fotang",
  		"north" : __DIR__"shufang",
  		"south" : __DIR__"kang3",
	]));
	set("objects", ([
  		__DIR__"npc/puyi": 1,
  		__DIR__"npc/yahuan": 2,
	]));
	set("coor/x", -180);
	set("coor/y", 4083);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
