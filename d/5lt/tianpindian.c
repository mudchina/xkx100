// Room: /d/5lt/tianpindian.c

inherit ROOM;

void create()
{
	set("short", "甜品店");
	set("long", @LONG
这是一个卖食品的小铺子，店里面有好多好多吃的东西，简直可以
用琳琅满目来形容。加上老板娘是村长的可心，台长的妹妹，所以店里
生意是村里头出了名的好!
LONG );
	set("exits", ([
		"north" : __DIR__"eroad1",
	]));
        set("objects", ([
		__DIR__"npc/blueeye": 1,
	]));
	set("no_fight", "1");
	set("coor/x", -140);
	set("coor/y", -10);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}