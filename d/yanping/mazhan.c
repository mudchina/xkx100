// /d/yanping/mazhan.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short","马站");
	set("long",@LONG
这个马站只为朝廷公文传递和官员接送，对老百姓和江湖人物却恕
不接待了。所以，虽然这里也有饭食，你却只有干挨额的份。由此往东
南，是通往福州的官道，北面马厩有驿马可以直达中原扬州，西边渡过
浮桥，就是延平府城了。
LONG);
	set("outdoors", "yanping");
	set("no_fight", "1");
	set("no_beg", "1");
	set("exits", ([
		"north" : __DIR__"majiu",
		"south" : __DIR__"guandao3",
		"westdown"  : __DIR__"fuqiao1",
	]));
	set("objects", ([
		__DIR__"npc/yibing": 1,
	]));
	set("coor/x", 1550);
	set("coor/y", -6170);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
