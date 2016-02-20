// Room: /d/luoyang/dukou.c
// Last modified by winder 2002.11.11

inherit  ROOM;

void  create  ()
{
	set("short",  "孟津渡口");
	set("long",  @LONG
这是洛阳城郊的孟津渡口，眼前就是黄河，浊浪涛天，近岸边稀稀
落落长了不少芦苇。码头上正泊着一艘乌篷船。
LONG);
	set("exits",  ([  /*  sizeof()  ==  2  */
		"east"      : __DIR__"futusi",
		"southwest" : __DIR__"road6",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -490);
	set("coor/y", 50);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
