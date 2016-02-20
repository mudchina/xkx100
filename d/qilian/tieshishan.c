// Room: /d/qilian/tieshishan.c
// Winder 2000/09/05 

inherit ROOM;

void create()
{
	object ob;
	set("short", "铁石山");
	set("long", @LONG
这里是祁连山以西四十里处，山势峥嶙，通山一色漆黑，光秃秃的
没有一点生气。遍山尽是锘石，其色如墨，火烧成铁，制器极刚利。从
这再往西走，就进入北祁连山区了。
LONG );
	set("outdoors", "qilian");
	set("exits", ([
		"east"      : __DIR__"qilianshan",
		"west"      : __DIR__"zibaipo",
		"northwest" : __DIR__"ailaoshan",
	]));
	set("objects", ([
//		__DIR__"obj/ironstone" : random(2),
	]));
	set("coor/x", -13000);
	set("coor/y", 3000);
	set("coor/z", 100);
	setup();
//	replace_program(ROOM);
  ob = new(__DIR__"obj/ironstone");
	if (ob->violate_unique())
	destruct(ob);
	else
	ob->move(this_object());
}