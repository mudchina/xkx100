// Room: /d/xingxiu/cangku.c
// Last Modified by winder on Feb. 28 2001

inherit ROOM;

void create()
{
	object fen1,fen2,fen3,fen4;
	
	set("short", "储藏室");
	set("long", @LONG
这里原来是一个长在山壁上的天然溶洞，是星宿派老巢的储藏处。
从外面看只是一个开在石山上的普通天然石洞，然因地点隐秘而且洞中
空气十分干燥，星宿派弟子将这里改造成了一个绝佳的储藏库。
LONG );
	set("exits", ([
	    "out" : __DIR__"xxroad5",
	]));
	set("objects", ([
		__DIR__"obj/yanwu" : 1,
		__DIR__"obj/hulu" : 2,
		"/clone/medicine/poison/menghanyao" : 1,
		"/clone/medicine/nostrum/qingxinsan" : 1,
		"/clone/book/dujing_1"  : 1
	]));

	set("coor/x", -50900);
	set("coor/y", 20120);
	set("coor/z", 30);
	setup();
	seteuid(getuid());
	fen1 = new("/clone/medicine/poison/duchongfen");
	fen2 = new("/clone/medicine/poison/bingpofen");
	fen3 = new("/clone/medicine/poison/honglinfen");
	fen4 = new("/clone/medicine/poison/yinlinfen");
	if (fen1->violate_unique()) destruct(fen1);
	else fen1->move(this_object());
	if (fen2->violate_unique()) destruct(fen2);
	else fen2->move(this_object());
	if (fen3->violate_unique()) destruct(fen3);
	else fen3->move(this_object());
	if (fen4->violate_unique()) destruct(fen4);
	else fen4->move(this_object());
	replace_program(ROOM);
}
